from pydantic import BaseModel, EmailStr
from datetime import datetime
from typing import Optional

from pydantic.types import conint

class Post(BaseModel):
    title: str
    content: str
    published: bool = True
    id: int
    # owner_id: int
    created_at: datetime
    