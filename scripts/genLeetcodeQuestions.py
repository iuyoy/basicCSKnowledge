import json
import shutil
import os
from leetcode import LeetCode
from secret import leetcodeCN, leetcodeUS
import collections

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
    allow_postfix = {'cpp': 'cpp', 'c': 'c', 'py': 'python3'}
    solution = ''
    for filename in filenames:
        postfix = filename.split('.')[-1]
        if postfix in allow_postfix:
            solution += '[{}](./{}/{}), '.format(allow_postfix[postfix],
                                                 dirpath.replace(' ', '%20'), filename)
    return solution[:-2]


# # Show all question of leetcode from https://leetcode.com/api/problems/all/
# def generateReadme(solutions={}):
#     with open("leetcode_all.json", 'r') as fp, open("leetcode_readme_outline.md", 'r') as ol_fp, open("../leetcode/README.md", 'w') as wp:
#         leetcode = json.load(fp)
#         lengths = len(leetcode['stat_status_pairs'])
#         questions = {}
#         print(lengths)
#         levels = {1: 'easy', 2: 'medium', 3: 'hard'}
#         lock = {False: '', True: ':lock:'}

#         # contents
#         wp.write(ol_fp.read())
#         # title of table
#         wp.write("""
# | id | title | Difficulty | Solution | Lock | Solved |
# | --- | --- | --- | --- | --- | --- |
# """)
#         # dir of questions
#         for i, q in enumerate(leetcode['stat_status_pairs'][::-1]):
#             # print(q['status'], type(q['status']))
#             # frontend_question_id and question_id differs
#             id, title, url_title, difficulty, locked, solved = q['stat']['frontend_question_id'], q['stat']['question__title'], q[
#                 'stat']['question__title_slug'], levels[q['difficulty']['level']], lock[q['paid_only']], status[q['status']]
#             solution = solutions[id] if id in solutions else ""
#             line = '|{}|[{}](https://leetcode.com/problems/{}/description/)|{}|{}|{}|{}|\n'.format(
#                 id, title, url_title, difficulty, solution, locked, solved)
#             # print(line)
#             wp.write(line)
#             # print()
#             # break


def flattenProblems(problems):
    """
    Question Example
    Para:
    [{
      "stat": {
        "question_id": 1634,
        "question__article__live": null,
        "question__article__slug": null,
        "question__title": "Clone N-ary Tree",
        "question__title_slug": "clone-n-ary-tree",
        "question__hide": false,
        "total_acs": 156,
        "total_submitted": 172,
        "frontend_question_id": 1490,
        "is_new_question": true
      },
      "status": null,
      "difficulty": {
        "level": 2
      },
      "paid_only": true,
      "is_favor": false,
      "frequency": 0,
      "progress": 0
    }, ...]

    """
    return {
        p['stat']['question_id']: {
            **(p['stat']),
            **(p['difficulty']),
            'status': p['status'],
            'paid_only': p['paid_only'],
        } for p in problems
    }


def mergeProblemStatus(problemsCN={}, problemsUS={}):
    problems = {}
    questionIDs = set(problemsCN.keys()) | set(problemsCN.keys())
    for qid in questionIDs:
        problems[qid] = {
            'cn': {},
            'us': {},
            'status': None
        }
        if qid in problemsCN:
            problems[qid]['cn'] = problemsCN[qid]
            problems[qid]['status'] = problemsCN[qid]['status']
        if qid in problemsUS:
            problems[qid]['us'] = problemsUS[qid]
            problems[qid]['us']['frontend_question_id'] = str( problemsUS[qid]['frontend_question_id'])
            if not problems[qid]['status'] or problemsUS[qid]['status'] == 'ac':
                problems[qid]['status'] = problemsUS[qid]['status']
    return problems
# Show all question of leetcode from https://leetcode.com/api/problems/all/


LEVELS = {1: 'easy', 2: 'medium', 3: 'hard'}
LOCK_SIGN = {False: '', True: ':lock:'}
STATUS_SIGN = {'ac': ':white_check_mark:', None: '', 'notac': ':x:'}


def generateReadme(problems={}, solutions={}):
    print(f'Problems: {len(problems)}, Solutions:{len(solutions)}')
    problems = sorted(problems.items())
    with open("leetcode_readme_outline.md", 'r') as ol_fp, open("../leetcode/README.md", 'w') as wp:
        # contents
        wp.write(ol_fp.read())
        # title of table
        wp.write("""
| id | area | title | Difficulty | Solution | Lock | Solved | RawID |
| --- | --- | --- | --- | --- | --- | --- | --- |
""")
        # dir of questions
        for id, info in problems:
            area = []
            front_id = []
            title = []
            difficulty = []
            locked = []
            solved = STATUS_SIGN[info['status']]
            for a in ['cn', 'us']:
                if info[a]:
                    area.append(a.upper())
                    front_id.append(info[a]['frontend_question_id'])
                    title.append(
                        f"[{info[a]['question__title']}](https://leetcode{'-cn' if a == 'cn' else ''}.com/problems/{info[a]['question__title_slug']}/description/)")
                    difficulty.append(LEVELS[info[a]['level']])
                    locked.append(LOCK_SIGN[info[a]['paid_only']])

            fid = front_id[-1]
            solution = solutions[fid] if fid in solutions else ""
            if fid == front_id[0]:
                front_id = [fid]
            print(area, front_id, title, difficulty, locked, solved)
            line = f"| {'<br>'.join(front_id)} |{'<br>'.join(area)}| {'<br>'.join(title)} | {'<br>'.join(difficulty)} | {solution} | {'<br>'.join(locked)} | {solved} | {id} |\n"
            wp.write(line)
            # print()
            # break


def main():
    lcUS = LeetCode(leetcodeUS['cookie'], type='us')
    problemsUS = lcUS.getAllProblems()
    problemsUS = flattenProblems(problemsUS['stat_status_pairs'])

    lcCN = LeetCode(leetcodeCN['cookie'], type='cn')
    problemsCN = lcCN.getAllProblems()
    problemsCN = flattenProblems(problemsCN['stat_status_pairs'])

    problems = mergeProblemStatus(problemsCN, problemsUS)
    solutions = listSolutions()
    generateReadme(problems, solutions)

if __name__ == '__main__':
    main()
    # solutions = listSolutions()
    # generateReadme(solutions)
