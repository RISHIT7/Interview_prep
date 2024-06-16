from fastapi import APIRouter, Depends, HTTPException, Response, status
from sqlalchemy.orm import Session

from .. import database, schemas, models, utils

router = APIRouter(
    tags=['Authentication']
)

@router.post('/login')
def login(user_cred: schemas.UserLogin, db: Session = Depends(database.get_db)):
    user = db.query(models.User).filter(models.User.email == user_cred.email).first()
    
    if not user:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail='Invalid Credentials')

    if not utils.verify(user_cred.password, user.password):
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail='Invalid Credentials')
    
    # create a token
    # return a token
    
    return {'token': 'example token '}