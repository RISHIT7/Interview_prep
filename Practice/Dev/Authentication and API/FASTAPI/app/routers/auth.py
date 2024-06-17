from fastapi import APIRouter, Depends, HTTPException, Response, status
from fastapi.security.oauth2 import OAuth2PasswordRequestForm
from sqlalchemy.orm import Session

from .. import database, schemas, models, utils
from . import Oauth2

router = APIRouter(
    tags=['Authentication']
)
@router.post('/login')
def login(user_cred: OAuth2PasswordRequestForm = Depends(), db: Session = Depends(database.get_db)):
    user = db.query(models.User).filter(
        models.User.email == user_cred.username
    ).first()
    
    if not user:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail='Invalid Credentials')

    if not utils.verify(user_cred.password, user.password):
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND, 
                            detail='Invalid Credentials')
    
    # create a token
    access_token = Oauth2.create_access_token(data={
        'user_id': user.id,
    })
    
    # return a token
    
    return {'token': access_token, 'token_type': 'bearer'}