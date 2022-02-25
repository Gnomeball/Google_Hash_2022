from dataclasses import dataclass

@dataclass
class Skill:
    name: str
    level: int

    filled: bool = False

@dataclass
class Contributor:
    name: str
    n_skills: int
    skills: [Skill]

    used: bool = False

@dataclass
class Project:
    name: str
    days: int
    score: int
    before: int
    n_roles: int
    roles: [Skill]

    scorePerDay: float
    completed: bool = False
