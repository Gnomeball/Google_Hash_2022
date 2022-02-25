import random, sys

from objects import Skill
from objects import Contributor
from objects import Project

def weight(self):
    return self.scorePerDay

f = sys.argv[1]

# * Parser

input_data = [line.strip() for line in open(f"{f}.txt", "r").readlines()]

n_contributors, n_projects = input_data.pop(0).split(" ")

contributors = []

for c in range(0, int(n_contributors)):
    name, n_skills = input_data.pop(0).split(" ")
    skills = []
    for s in range(0, int(n_skills)):
        skill, level = input_data.pop(0).split(" ")
        skills.append(Skill(skill, int(level)))
    contributors.append(Contributor(name, n_skills, skills))

projects = []

for p in range(0, int(n_projects)):
    name, days, score, before, n_roles = input_data.pop(0).split(" ")
    skills = []
    for s in range(0, int(n_roles)):
        skill, level = input_data.pop(0).split(" ")
        skills.append(Skill(skill, int(level)))
    projects.append(Project(name, int(days), int(score), int(before), int(n_roles), skills, int(score)/int(days)))

# * Sort by weight

projects.sort(key = weight, reverse = True)

# * Magic

output_data = []

for p in projects:
    random.shuffle(contributors)
    contributors_for_this = []
    if not p.completed:
        for r in p.roles:
            isRedundantSkill = False
            for contributor in contributors_for_this:
                for skill in contributor.skills:
                    if skill.name == r.name and skill.level >= r.level:
                        isRedundantSkill = True
            for c in contributors:
                if not c.used:
                    for s in c.skills:
                        if s.name == r.name and s.level == r.level:
                            contributors_for_this.append(c)
                            c.used = True
                            r.filled = True
                    if not r.filled:
                        for s in c.skills:
                            if isRedundantSkill:
                                if s.name == r.name and s.level == r.level - 1:
                                    contributors_for_this.append(c)
                                    c.used = True
                                    r.filled = True
                            else:
                                if s.name == r.name and s.level >= r.level:
                                    contributors_for_this.append(c)
                                    c.used = True
                                    r.filled = True
                if r.filled:
                    break
            if not r.filled:
                break

        if p.n_roles == len(contributors_for_this):
            output_data.append([p, contributors_for_this])
            for i in range(0, len(contributors_for_this)):
                for c_skill in contributors_for_this[i].skills:
                    if c_skill.name == p.roles[i].name:
                        if c_skill.level <= p.roles[i].level:
                            c_skill.level += 1

            p.completed = True
        for cont in contributors_for_this: cont.used = False

print(len(output_data))
for o in output_data:
    print(o[0].name)
    for c in o[1]:
        print(c.name, end = " ")
    print()