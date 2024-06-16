from pydantic import BaseModel, EmailStr
from datetime import datetime
from typing import Optional

class PostBase(BaseModel):
    title: str
    content: str
    published: Optional[bool] = True
    rating: Optional[int] = 0
    
class PostCreate(PostBase):
    pass

class Post(PostBase):
    id: int
    created_at: datetime

    class Config:
        from_attributes = True # allows us to return a Post object from the database, not a dict

class UserCreate(BaseModel):
    email: EmailStr
    password: str
    
class UserOut(BaseModel):
    id: int
    email: EmailStr
    created_at: datetime
    
    class Config:
        from_attributes = True # allows us to return a Post object from the database, not a dict

class UserLogin(BaseModel):
    email: EmailStr
    password: str