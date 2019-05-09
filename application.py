from flask import Flask, redirect, render_template, request, url_for

import helpers
from analyzer import Analyzer

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():

    # validate screen_name
    screen_name = request.args.get("screen_name", "")
    if not screen_name:
        return redirect(url_for("index"))
    print(screen_name)

    # get screen_name's tweets
    tweets = helpers.get_user_timeline(screen_name, 100)
    # TODO - if no tweets, redirect to index
    if tweets == None:
        return redirect(url_for("index"))

    positive, negative, neutral = 0.0, 0.0, 100.0


    # Zamyla - initialize Analyzer as you learned in analyzer.py
    analyzer= Analyzer(positive, negative)

    #Zamyla - iterate over tweets
    for tweet in tweets:
        #score each word
        score = analyzer.analyze(tweet)
        # track pos neg neut
        if score > 0:
            positive += 1
        elif score < 0:
            negative += 1
        else:
            neutral += 1

    # generate chart
    chart = helpers.chart(positive, negative, neutral)

    # render results
    return render_template("search.html", chart=chart, screen_name=screen_name)
