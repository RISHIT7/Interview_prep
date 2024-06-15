# normalURL/docs for Swagger UI documentation and testing automatically without writing code!
from fastapi import FastAPI, Response, status, HTTPException, Depends
from sqlalchemy.orm import Session
from typing import List

from . import models, schemas, secret
from .database import get_db, engine


models.Base.metadata.create_all(bind=engine)

app = FastAPI()
DATABASE_PASSWORD = secret.secret()

@app.get("/")
async def root():
    return {"message": "API running!"}

@app.get('/posts', response_model = List[schemas.Post])
def get_posts(db: Session = Depends(get_db)):
    # cursor.execute("""
    #                SELECT * FROM posts;
    #                """)
    # posts = cursor.fetchall() 

    posts = db.query(models.Post).all()
    return posts

@app.post('/posts', status_code=status.HTTP_201_CREATED, response_model=schemas.Post)
def create_posts(post: schemas.PostCreate, db: Session = Depends(get_db)): # from the body
    # cursor.execute("""
    #                  INSERT INTO posts (title, body, published, rating)
    #                     VALUES (%(title)s, %(body)s, %(published)s, %(rating)s)
    #                  RETURNING *;   
    #                  """, post.title, post.body, post.published, post.rating)
    # new_post = cursor.fetchone()
    # conn.commit()

    new_post = models.Post(**post.model_dump())
    db.add(new_post)
    db.commit()
    db.refresh(new_post)
    return new_post

@app.get('/posts/{id}', response_model = schemas.Post)
def get_post(id: int,  db: Session = Depends(get_db)):
    # cursor.execute("""
    #                  SELECT * FROM posts WHERE id = %(id)s;
    #                     """, {'id': id})
    # my_post = cursor.fetchone()
    post = db.query(models.Post).filter(models.Post.id == id).first()
    
    if not post:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    return post

@app.delete('/posts/{id}')
def delete_post(id: int, db: Session = Depends(get_db)):
    # cursor.execute("""
    #                  DELETE FROM posts WHERE id = %(id)s
    #                  RETURNING *;
    #                  """, {'id': id})
    # deleted_post = cursor.fetchone()
    # conn.commit()
    post_query = db.query(models.Post).filter(models.Post.id == id)
    post = post_query.first()
    
    if post == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    post_query.delete(synchronize_session=False)
    db.commit()
    
    return Response(status_code=status.HTTP_204_NO_CONTENT)

@app.put('/posts/{id}', response_model=schemas.Post)
def update_post(id: int, updated_post: schemas.PostCreate, db: Session = Depends(get_db)):
    # cursor.execute("""
    #                  UPDATE posts
    #                  SET title = %(title)s, body = %(body)s, published = %(published)s, rating = %(rating)s
    #                  WHERE id = %(id)s
    #                  RETURNING *;
    #                  """, {'id': id, 'title': post.title, 'body': post.body, 'published': post.published, 'rating': post.rating})
    # updated_post = cursor.fetchone()
    # conn.commit()
    
    post_query = db.query(models.Post).filter(models.Post.id == id)
    post = post_query.first()
    
    if post == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    post_query.update(updated_post.model_dump())
    db.commit()
    return post_query.first()

@app.post('/users', status_code = status.HTTP_201_CREATED, response_model=schemas.UserOut)
def create_user(user: schemas.UserCreate, db: Session = Depends(get_db)):
    new_user = models.User(**user.model_dump())
    db.add(new_user)
    db.commit()
    db.refresh(new_user)

    return new_user