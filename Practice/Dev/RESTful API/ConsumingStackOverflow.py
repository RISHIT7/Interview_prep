import requests, json

def get_question():
    url = 'https://api.stackexchange.com/2.2/questions?order=desc&sort=activity&site=stackoverflow'
    response = requests.get(url)
    questions = response.json()
    return questions

def main():
    questions = get_question()
    for question in questions['items']:
        print(question['title'])
        if question['answer_count'] == 0:
            print('Unanswered question')
        else:
            print(question['link'])
        print()

if __name__ == "__main__":
    main()