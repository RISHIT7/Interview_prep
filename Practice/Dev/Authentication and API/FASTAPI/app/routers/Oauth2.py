from jose import JWTError, jwt
from datetime import datetime, timedelta

# SECRET_KEY
# Algorithm
# Expiration time of the token

SECRET_KEY = "ffg9sgfhs6f85g6575d5f96s9gdf6g75dghsd6fg9s60df6g975sdgh67d3fn543df4s8b9dfb8"
ALGORITHM = "HS256"
ACCESS_TOKEN_EXPIRE_MINUTES = 30

def create_access_token(data: dict):
    # data <- payload
    to_encode = data.copy()
    
    expire = datetime.now() + timedelta(minutes=ACCESS_TOKEN_EXPIRE_MINUTES)
    to_encode.update({
        'exp': expire
    })
    
    encoded_jwt = jwt.encode(to_encode, SECRET_KEY, algorithm=ALGORITHM)
    
    return encoded_jwt