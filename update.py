import bs4
import requests
import os

login_page = "https://cses.fi/login/"
username = input("Enter your username: ")
password = input("Enter your password: ")

session = requests.Session()
response = session.get(login_page)
csrf = bs4.BeautifulSoup(response.text, "html.parser").find("input", {"name": "csrf_token"})["value"]
login_data = {
    "csrf_token": csrf,
    "nick": username,
    "pass": password
}
response = session.post(login_page, data=login_data)

if "Invalid username or password" in response.text:
    print("Invalid username or password")
    exit()

next_link = "https://cses.fi/problemset/"
problems_list = session.get(next_link)
soup = bs4.BeautifulSoup(problems_list.text, "html.parser")
folders = [tag.text.replace(" ", "") for tag in soup.find_all("h2")][1:]
for folder in folders:
    # if there isn't folder create it
    try:
        os.mkdir(folder)
    except:
        pass
problems_list = soup.find_all("ul", class_="task-list")[1:]
for idx, problem_list in enumerate(problems_list):
    txt = problem_list.prettify()
    txt = txt.split('<li class="task">')[1:]
    count = 0
    print(f"Checking {folders[idx]}")
    for problem in txt:
        if not "icon full" in problem:
            continue
        problem = problem.split('<a href="')[1].split('">')[0]
        problem_link = "https://cses.fi" + problem
        problem_page = session.get(problem_link)
        soup = bs4.BeautifulSoup(problem_page.text, "html.parser")
        problem_name = soup.find("h1").get_text().replace(" ", "") + ".cpp"
        if os.path.exists(f"{folders[idx]}/{problem_name}"):
            # print(f"{problem_name} already exists")
            continue
        problem_page = soup.find("div", class_="nav sidebar")
        submissions = problem_page.find_all("a")
        for submission in submissions:
            submission_link = submission["href"]
            # problems in the sidebar
            if "task" in submission_link:
                continue
            # wrong submissions
            if "zero" in submission.span["class"]:
                continue
            submission_link = "https://cses.fi" + submission_link
            submission_page = session.get(submission_link)
            soup = bs4.BeautifulSoup(submission_page.text, "html.parser")
            sharable_link = None
            # for each href
            for a in soup.find_all("a"):
                if "Share" in a.text:
                    sharable_link = a["href"]
                    break

            code_tag = soup.find("pre")
            code = code_tag.get_text()
            if sharable_link:
                code = "// https://cses.fi" + sharable_link + "\n" + code
            # Save the code to a file
            with open(f"{folders[idx]}/{problem_name}", "w") as file:
                file.write(code)
            print(f"{problem_name} saved")
            count += 1
            break
    if count == 0:
        print(f"No new problems in {folders[idx]}")
    print()
