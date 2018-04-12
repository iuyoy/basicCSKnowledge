import json

# Show all question of leetcode from https://leetcode.com/api/problems/all/

with open("leetcode_all.json", 'r') as fp:
    with open("leetcode_all.md", 'w') as wp:
        leetcode = json.load(fp)
        lengths = len(leetcode['stat_status_pairs'])
        questions = {}
        print(lengths)
        # | id  | title | Difficulty | Solution | Lock|
        # | --- | ----- | ---------- | -------- | --- |
        levels = {1:'easy', 2:'medium', 3:'hard'}
        lock = {False:'', True:':lock:'}

        for q in leetcode['stat_status_pairs'][::-1]:
            wp.write('|{}|[{}](https://leetcode.com/problems/{}/description/)|{}| |{}|\n'.format(q['stat']['question_id'],q['stat']['question__title'],q['stat']['question__title_slug'],levels[q['difficulty']['level']], lock[q['paid_only']]))
            # print()
            # break;
