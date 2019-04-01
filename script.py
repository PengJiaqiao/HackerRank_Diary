import os,sys
import pyperclip

# |001|[Compare the Triplets](https://www.hackerrank.com/challenges/compare-the-triplets/problem) |[c++](./src/Compare_the_Triplets/Compare_the_Triplets.cpp) |python|Easy|

md_file = './README.md'

if __name__ == "__main__":
    name = sys.argv[1]
    name_ = sys.argv[1]
    for arg in sys.argv[2:-2]:
        name = name + ' ' + arg
        name_ = name_ + '_' + arg

    with open(md_file) as f:
        lines = f.readlines()
    num = lines[-1].split('|')[1]
    num += 1

    path = './src/' + num + '_' + name_
    folder = os.path.exists(path)
    if not folder:
        os.makedirs(path)
    file = open(path + '/' + name_ + '.cpp','w')
    file.close()
    text = '|' + num + '|' + '[' + name + ']' + '(' + sys.argv[-2] + ')' + ' ' + '|[c++]' + '(./src/' + num + '_' + name_ + '/' + name_ + '.cpp) ' + '|python|' + sys.argv[-1] + '|' + '\n'
    print(text)
	# pyperclip.copy(text)

    f = open(md_file, 'a')
    f.writelines(text)
    f.close()
