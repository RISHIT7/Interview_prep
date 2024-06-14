# normalURL/docs for Swagger UI documentation and testing automatically without writing code!
from typing import Optional
from fastapi import FastAPI, Response, status, HTTPException, Depends
from pydantic import BaseModel
import psycopg2
from psycopg2.extras import RealDictCursor
import time
from . import secret
from .database import get_db
from .models import Post
from sqlalchemy.orm import Session
from sqlalchemy.sql.functions import func

app = FastAPI()
DATABASE_PASSWORD = secret.secret()

while True:
    try:
        conn = psycopg2.connect(host = 'localhost', database= 'FAST-API-Database', user='postgres', 
                            password = DATABASE_PASSWORD, cursor_factory = RealDictCursor) # bad practice
        cursor = conn.cursor()
        print('Database connection successful')
        break
    except Exception as error:
        print('Database connection error')
        print("Error occured: ", error)
        time.sleep(5) # if this is issue with the internet, it will keep trying to connect

@app.get("/")
async def root():
    return {"message": "Hello World"}

@app.get('/posts')
def get_posts(db: Session = Depends(get_db)):
    # cursor.execute("""
    #                SELECT * FROM posts;
    #                """)
    # posts = cursor.fetchall() 

    posts = db.query(Post).all()
    return {'data': posts}

@app.post('/posts', status_code=status.HTTP_201_CREATED)
def create_posts(post: Post, db: Session = Depends(get_db)): # from the body
    # cursor.execute("""
    #                  INSERT INTO posts (title, body, published, rating)
    #                     VALUES (%(title)s, %(body)s, %(published)s, %(rating)s)
    #                  RETURNING *;   
    #                  """, post.title, post.body, post.published, post.rating)
    # new_post = cursor.fetchone()
    # conn.commit()

    new_post = Post(**post.model_dump())
    db.add(new_post)
    db.commit()
    return new_post

@app.get('/posts/{id}')
def get_post(id: int,  db: Session = Depends(get_db)):
    # cursor.execute("""
    #                  SELECT * FROM posts WHERE id = %(id)s;
    #                     """, {'id': id})
    # my_post = cursor.fetchone()
    post = db.query(Post).filter(Post.id == id).first()
    
    if not post:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    return {'data': post}

@app.delete('/posts/{id}')
def delete_post(id: int, db: Session = Depends(get_db)):
    # cursor.execute("""
    #                  DELETE FROM posts WHERE id = %(id)s
    #                  RETURNING *;
    #                  """, {'id': id})
    # deleted_post = cursor.fetchone()
    # conn.commit()
    post_query = db.query(Post).filter(Post.id == id)
    post = post_query.first()
    
    if post == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    post_query.delete(synchronize_session=False)
    db.commit()
    
    return Response(status_code=status.HTTP_204_NO_CONTENT)

@app.put('/posts/{id}')
def update_post(id: int, updated_post: Post, db: Session = Depends(get_db)):
    # cursor.execute("""
    #                  UPDATE posts
    #                  SET title = %(title)s, body = %(body)s, published = %(published)s, rating = %(rating)s
    #                  WHERE id = %(id)s
    #                  RETURNING *;
    #                  """, {'id': id, 'title': post.title, 'body': post.body, 'published': post.published, 'rating': post.rating})
    # updated_post = cursor.fetchone()
    # conn.commit()
    
    post_query = db.query(Post).filter(Post.id == id)
    post = post_query.first()
    
    if post == None:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f"Post with id {id} not found")
    
    post_query.update(updated_post.model_dump())
    db.commit()
    return post_query.first()
