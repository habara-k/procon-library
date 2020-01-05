import os
import re
import shutil
import subprocess


def find_all_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            yield os.path.join(root, file)


def dump_snippet():
    BASE_FILE = 'vim/base.cpp.snip'
    SNIP_FILE = 'cpp.snip'

    shutil.copy(BASE_FILE, SNIP_FILE)

    with open(SNIP_FILE,'a') as file:

        for src_path in find_all_files('lib'):



            src_title, fext = os.path.splitext(os.path.basename(src_path))
            if fext != '.cpp':
                continue

            if src_title == 'template':
                continue

            file.write('\n\nsnippet ' + src_title + '\n')

            with open(src_path,'r') as src:

                for row in src:
                    if re.match('#', row):
                        continue

                    if row == '\n':
                        file.write(row)
                        continue

                    file.write('    ' + row)


def dump_template():
    BASE_FILE = 'vim/base-template.cpp'
    TEMPLATE_FILE = 'base-main.cpp'
    SOURCE_FILE = 'lib/template.cpp'

    with open(TEMPLATE_FILE,'w') as file:
        with open(SOURCE_FILE,'r') as src:

            for row in src:
                if re.match('#ifndef', row):
                    continue
                if re.match('#define TEMPLATE', row):
                    continue
                if re.match('#endif', row):
                    continue

                file.write(row)

        file.write('\n\n')

        with open(BASE_FILE,'r') as base:
            for row in base:
                file.write(row)


def push_to_neosnippet():
    branch = 'neosnippet'
    try:
        subprocess.check_call(['git', 'checkout', branch])
    except subprocess.CalledProcessError:
        subprocess.check_call(['git', 'checkout', '--orphan', branch])

    url = 'https://{}:{}@github.com/{}.git'.format(
            os.environ['GITHUB_ACTOR'],
            os.environ['GITHUB_TOKEN'],
            os.environ['GITHUB_REPOSITORY'])

    subprocess.check_call(['git', 'config', '--global', 'user.email', 'noreply@github.com'])
    subprocess.check_call(['git', 'config', '--global', 'user.name', 'GitHub'])

    subprocess.check_call(['git', 'reset'])
    subprocess.check_call(['git', 'add', 'cpp.snip'])

    if subprocess.run(['git', 'diff', '--quiet', '--staged']).returncode:
        subprocess.check_call(['git', 'commit', '-m', 'Dump snippet'])
        subprocess.check_call(['git', 'push', url, 'HEAD'])


def push_to_vim_template():
    branch = 'vim-template'
    try:
        subprocess.check_call(['git', 'checkout', branch])
    except subprocess.CalledProcessError:
        subprocess.check_call(['git', 'checkout', '--orphan', branch])

    url = 'https://{}:{}@github.com/{}.git'.format(
            os.environ['GITHUB_ACTOR'],
            os.environ['GITHUB_TOKEN'],
            os.environ['GITHUB_REPOSITORY'])

    subprocess.check_call(['git', 'config', '--global', 'user.email', 'noreply@github.com'])
    subprocess.check_call(['git', 'config', '--global', 'user.name', 'GitHub'])

    subprocess.check_call(['git', 'reset'])
    subprocess.check_call(['git', 'add', 'base-main.cpp'])

    if subprocess.run(['git', 'diff', '--quiet', '--staged']).returncode:
        subprocess.check_call(['git', 'commit', '-m', 'Dump template'])
        subprocess.check_call(['git', 'push', url, 'HEAD'])


if __name__ == '__main__':
    dump_snippet()
    push_to_neosnippet()

    #dump_template()
    #push_to_vim_template()
