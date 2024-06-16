import sqlite3

try:
    conn = sqlite3.connect('./database.db')
    cursor = conn.cursor()
    query = """
    DELETE FROM users;
    """

    log = cursor.execute(query)
    print(log.fetchall())
    conn.commit()
    cursor.close()
    
except sqlite3.Error as e:
    print(e)