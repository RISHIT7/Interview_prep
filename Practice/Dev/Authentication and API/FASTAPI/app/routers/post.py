from fastapi import Response, status, HTTPException, Depends, APIRouter
from sqlalchemy.orm import Session
from typing import List

from .. import models, schemas, oauth2
from ..database import get_db

router = APIRouter(
    prefix = '/posts',
    tags=['Posts']
)

@router.get('/', response_model = List[schemas.Post])
def get_posts(db: Session = Depends(get_db), curr_user: int = Depends(oauth2.get_curr_user)):
    posts = db.query(models.Post).all()
    return posts

@router.post('/', status_code=status.HTTP_201_CREATED, response_model=schemas.Post)
def create_posts(post: schemas.PostCreate, db: Session = Depends(get_db), curr_user: int = Depends(oauth2.get_curr_user)): # from the body
    new_post = models.Post(**post.model_dump())
    db.add(new_post)
    db.commit()
    db.refresh(new_post)
    return new_post

@router.get('/{id}', response_model = schemas.Post)
def get_post(id: int,  db: Session = Depends(get_db), curr_user: int = Depends(oauth2.get_curr_user)):
    post = db.query(models.Post).filter(models.Post.id == id).first()
    
    if not post:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    return post

@router.delete('/{id}')
def delete_post(id: int, db: Session = Depends(get_db), curr_user: int = Depends(oauth2.get_curr_user)):
    post_query = db.query(models.Post).filter(models.Post.id == id)
    post = post_query.first()
    
    if post == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    post_query.delete(synchronize_session=False)
    db.commit()
    return Response(status_code=status.HTTP_204_NO_CONTENT)

@router.put('/{id}', response_model=schemas.Post)
def update_post(id: int, updated_post: schemas.PostCreate, db: Session = Depends(get_db), curr_user: int = Depends(oauth2.get_curr_user)):
    post_query = db.query(models.Post).filter(models.Post.id == id)
    post = post_query.first()
    
    if post == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    post_query.update(updated_post.model_dump())
    db.commit()
    return post_query.first()
