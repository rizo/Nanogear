#!/usr/bin/python
# Generate Qt-style headers
#
import re
import os.path

RE_CLASSNAME = re.compile(r'\s+\*\s+\\class (.*)$')

def walker(arg, dirname, names):
    for file in names:
        if '.h' == os.path.splitext(file)[1]:
            f = open(os.path.join(dirname, file), 'r')
            for line in f:
                m_classname = RE_CLASSNAME.search(line)
                if m_classname:
                    print '->', file, 'has the required doclet'
                    qtheader = open(os.path.join(dirname, m_classname.group(1)), 'w')
                    qtheader.write('#include "./'+file+'"\n')
                    qtheader.close()


if __name__ == "__main__":
    os.path.walk('.', walker, None)
    
