import sqlite3

try:
    conn = sqlite3.connect('./database.db')
    cursor = conn.cursor()
    query = """
    INSERT INTO posts (title, content, owner_id)
    VALUES ('First Post', 'This is the first post', 1)
    """

    log = cursor.execute(query)
    print(log.fetchall())
    conn.commit()
    cursor.close()
    
except sqlite3.Error as e:
    print(e)