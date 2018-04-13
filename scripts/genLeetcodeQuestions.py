import json
import shutil
import os
# Generate readme.md file with questions and solutions

# List solutions
def listSolutions():
    solutions = {}
    for dirpath, dirnames, filenames in os.walk('../leetcode'):
        dir = dirpath.split('/')[-1]
        if('.' in dir):
            id = int(dir.split('.')[0])
            # print(id, getFilename(dir, filenames))
            solutions[id] = getFilename(dir, filenames)
    return solutions

# generate markdown url
def getFilename(dirpath, filenames):
    allow_postfix = ['cpp', 'c']
    solution = ''
    for filename in filenames:
        postfix = filename.split('.')[-1]
        if postfix in allow_postfix:
            solution += '[{}](./{}/{}), '.format(postfix, dirpath.replace(' ', '%20'), filename)
    return solution[:-2]



# Show all question of leetcode from https://leetcode.com/api/problems/all/
def generateReadme(solutions = {}):
    with open("leetcode_all.json", 'r') as fp, open("leetcode_readme_outline.md", 'r') as ol_fp, open("../leetcode/README.md", 'w') as wp:
        leetcode = json.load(fp)
        lengths = len(leetcode['stat_status_pairs'])
        questions = {}
        print(lengths)
        levels = {1:'easy', 2:'medium', 3:'hard'}
        lock = {False:'', True:':lock:'}
        status = {'ac':':white_check_mark:', None:'', 'notac':':x:'}
        # contents
        wp.write(ol_fp.read())
        # title of table
        wp.write("""
| id | title | Difficulty | Solution | Lock | Solved |
| --- | --- | --- | --- | --- | --- |
""")
        # dir of questions
        for q in leetcode['stat_status_pairs'][::-1]:
            # print(q['status'], type(q['status']))
            id, title, url_title, difficulty, locked, solved = q['stat']['question_id'],q['stat']['question__title'],q['stat']['question__title_slug'],levels[q['difficulty']['level']], lock[q['paid_only']], status[q['status']]
            solution = solutions[id] if id in solutions else ""
            line = '|{}|[{}](https://leetcode.com/problems/{}/description/)|{}|{}|{}|{}|\n'.format(id, title, url_title, difficulty, solution, locked, solved)
            # print(line)
            wp.write(line)
            # print()
            # break
if __name__ == '__main__':

    solutions = listSolutions()
    generateReadme(solutions)
