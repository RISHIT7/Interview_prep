# normalURL/docs for Swagger UI documentation and testing automatically without writing code!
from typing import Optional
from fastapi import FastAPI, Response, status, HTTPException
from pydantic import BaseModel
import psycopg2
from psycopg2.extras import RealDictCursor
import time
from . import secret

app = FastAPI()
DATABASE_PASSWORD = secret.secret()

serial_id = 0

class Post(BaseModel):
    title: str
    body: str
    published: bool = True
    rating: Optional[int] = None

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
def get_posts():
    cursor.execute("""
                   SELECT * FROM posts;
                   """)
    posts = cursor.fetchall() 
    return {'data': posts}

@app.post('/posts', status_code=status.HTTP_201_CREATED)
def create_post(post: Post): # from the body
    cursor.execute("""
                     INSERT INTO posts (title, body, published, rating)
                        VALUES (%(title)s, %(body)s, %(published)s, %(rating)s);
                     """, post.title, post.body, post.published, post.rating)
    return {'data': "created successfully"}

@app.get('/posts/{id}')
def get_post(id: int):
    cursor.execute("""
                     SELECT * FROM posts WHERE id = %(id)s;
                        """, {'id': id})
    my_post = cursor.fetchone()
    return {'data': my_post}

@app.delete('/posts/{id}')
def delete_post(id: int, response: Response):
    cursor.execute("""
                     DELETE FROM posts WHERE id = %(id)s;
                     """, {'id': id})
    response.status_code = status.HTTP_204_NO_CONTENT
    return {'data': f'Post deleted with id: {id}'}

@app.put('/posts/{id}')
def update_post(id: int, post: Post):
    cursor.execute("""
                     UPDATE posts
                     SET title = %(title)s, body = %(body)s, published = %(published)s, rating = %(rating)s
                     WHERE id = %(id)s;
                     """, {'id': id, 'title': post.title, 'body': post.body, 'published': post.published, 'rating': post.rating})
    return {'data': f'Post with id: {id} updated successfully'}
