from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker

<<<<<<< HEAD
SQLALCHEMY_DATABASE_URL = "postgresql://postgres:JEEAdvanced#633@localhost/FAST-API-Database"
=======
from .secret import secret

SQLALCHEMY_DATABASE_URL = "postgresql://postgres:" + secret() + "@localhost/FAST-API-Database"
>>>>>>> 1e6140f8698eada048e053899a67573c97e4d1b1

engine = create_engine(SQLALCHEMY_DATABASE_URL)

SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)

Base = declarative_base()

def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()
        
# while True:

#     try:
#         conn = psycopg2.connect(host='localhost', database='fastapi', user='postgres',
#                                 password='password123', cursor_factory=RealDictCursor)
#         cursor = conn.cursor()
#         print("Database connection was succesfull!")
#         break
#     except Exception as error:
#         print("Connecting to database failed")
#         print("Error: ", error)
#         time.sleep(2)