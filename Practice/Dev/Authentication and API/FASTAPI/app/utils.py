from passlib.context import CryptContext

pwd_context = CryptContext(schemes=["bcrypt"], deprecated="auto")

def hash(password: str) -> str:
    return pwd_context.hash(password)

def verify(password: str, hashed_password: str) -> bool:
    return pwd_context.verify(password, hashed_password)