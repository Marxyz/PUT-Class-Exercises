import requests
from bs4 import BeautifulSoup
import os
import praw
import config
import datetime
import time
import winsound
import string

def bot_login():
    reddit = praw.Reddit(username = config.username, password = config.password, client_id = config.client_id, client_secret = config.client_secret
            , user_agent = "Areczek`s first reddit bot")
    return reddit
def run_bot(reddit):
    listOfSubmissions = []
    sub = reddit.subreddit("tokipona")
    print("Getting into [" + sub.display_name + "] subreddit.")
    now = datetime.datetime.now()
    nowtmstmp = now.timestamp()
    last_hour = now - datetime.timedelta(days = 14)
    lttmstmp = last_hour.timestamp()
    for submission in sub.submissions(lttmstmp,nowtmstmp):
        print("Found submission!")
        listOfSubmissions.append(submission)
        for comment in submission.comments.list():
          pass
        time.sleep(1)
    return listOfSubmissions

def GetLatestSubmissions():
        reddit = bot_login()
        list_OfSubmission = run_bot(reddit)
        return list_OfSubmission


def GetTokiDict():
    headers = {'user-agent': "Simple toki dictionary scrapper, marks.arkadiusz@outlook.com"}
    page = requests.get("http://tokipona.net/tp/janpije/dictionary.php",headers = headers)
    soup = BeautifulSoup(page.content, "html.parser")

    TokiPonaDict = {}
    dict = soup.findAll("tr")
    print("Getting Word Definitions from http://tokipona.net/tp/janpije/dictionary.php")
    for x in dict:
        key = ""
        value = ""
        try:
            key = x.contents[1].get_text()
            value = x.contents[3].get_text().replace("\xa0","")
        except Exception as exc:
            print(type(exc),exc.args,sep = ",")
        
        TokiPonaDict[key] = value
    return TokiPonaDict

def PrintContent(TokiPonaDict):
    for (key,value) in TokiPonaDict.items():
        print(key,value,sep = " - ")

def ReplaceUnwantedChars(text):
    for ch in ['\\','`','*','_','{','}','[',']','(',')','>','#','+','-','.','!','$','\'','?','"']:
        if ch in text:
            text = text.replace(ch,"")
    return text

def main():
    TokiPonaDict = GetTokiDict()
    submissions = GetLatestSubmissions()
    TranslateSubmission(submissions,TokiPonaDict)


def TranslateSubmission(submissions,tokiPonaDict):
    for subs in submissions:
        print(subs.title)
        for word in ReplaceUnwantedChars(subs.title).split(" "):
            if word.lower() in tokiPonaDict.keys():
                print(word + " - " + tokiPonaDict[word.lower()])
        print("------------------------------------------")

def SaveToFile(string_filepath):
    with open(string_filepath,'w') as file:
        tokiPonaDict = GetTokiDict()
        for key,value in tokiPonaDict.items():
            data = key + ' - ' + value + os.linesep
            data = str(data)
            file.write(data)


# if name __main__
main();