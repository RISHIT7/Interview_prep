from typing import Optional
from fastapi import FastAPI, Response, status, HTTPException
from pydantic import BaseModel # for validation

app = FastAPI()

serial_id = 0
my_posts = []

class Post(BaseModel):
    title: str
    body: str
    published: bool = True
    rating: Optional[int] = None

@app.get("/")
async def root():
    return {"message": "Hello World"}

@app.get('/posts')
def get_posts():
    return {'data': 'Posts'}

@app.post('/posts', status_code=status.HTTP_201_CREATED)
def create_post(post: Post): # from the body
    post_dict = post.model_dump()
    post_dict['id'] = serial_id
    serial_id += 1 # makeshift database
    my_posts.append(post_dict) # makeshift database
    return {'data': post_dict}
# title: str, body: str <- want to validate the request body

# retrieving a single post
@app.get('/posts/{id}')
def get_post(id: int, response: Response):
    if (id < 0) or (id >= len(my_posts)):
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail=f'Post with id: {id} not found')

    return {'data': my_posts[id]}