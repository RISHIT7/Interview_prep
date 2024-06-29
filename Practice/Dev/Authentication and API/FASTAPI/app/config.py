from pydantic_settings import BaseSettings

from .env import env_variables

class Settings(BaseSettings):
    DATABASE_URL: str = env_variables.DATABASE_URL
    SECRET_KEY: str = env_variables.SECRET_KEY
    ALGORITHM: str = env_variables.ALGORITHM
    ACCESS_TOKEN_EXPIRE_MINUTES: int = env_variables.ACCESS_TOKEN_EXPIRE_MINUTES
    
    class Config:
        env_file = ".env"

settings = Settings()
