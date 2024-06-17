from jose import JWTError, jwt
from datetime import datetime, timedelta, timezone
from fastapi import Depends, status, HTTPException
from fastapi.security import OAuth2PasswordBearer

from . import schemas

oauth2_scheme = OAuth2PasswordBearer(tokenUrl='login')

# SECRET_KEY
# Algorithm
# Expiration time of the token

SECRET_KEY = "ffg9sgfhs6f85g6575d5f96s9gdf6g75dghsd6fg9s60df6g975sdgh67d3fn543df4s8b9dfb8"
ALGORITHM = "HS256"
ACCESS_TOKEN_EXPIRE_MINUTES = 30

def create_access_token(data: dict):
    # data <- payload
    to_encode = data.copy()
    
    expire = datetime.now(timezone.utc) + timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    to_encode.update({
        'exp': expire
    })
    
    encoded_jwt = jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)
    
    return encoded_jwt

def verify_access_token(token: str, credentials_exceptions):
    try:
        payload = jwt.decode(token, SECRET_KEY, algorithms=[ALGORITHM])
        id: str = payload.get('user_id')
        
        if id is None:
            raise credentials_exceptions
        
        token_data = schemas.TokenData()
        token_data.id = id
    
    except JWTError:
        raise credentials_exceptions
    
    return token_data

def get_curr_user(token: str = Depends(oauth2_scheme)):
    credentials_exception = HTTPException(
        status_code=status.HTTP_401_UNAUTHORIZED,
        detail='Could not validate credentials',
        headers={'WWW-Authenticate': 'Bearer'}
    )
    
    return verify_access_token(token, credentials_exception)