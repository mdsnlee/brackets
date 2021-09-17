#!/usr/bin/python3

import os
import unittest
from contextlib import contextmanager
from ShellOutput import ShellOutput

#pass the file in as an argument
EXECUTABLE = "../bin/brackets"

def getOutput(file):
    with ShellOutput() as out:
        os.system(EXECUTABLE + " " + file)
    return out.capturedtext


class Test_Success(unittest.TestCase):
    
    @classmethod
    def setUpClass(CLS):
        print("success set up")

    def test_success_01(self):
        return self.assertEqual(getOutput("test.txt"), "valid")


    @classmethod
    def tearDownClass(CLS):
        print("")



#this file will only be run if it's on the executed line
#fake function
#automatically runs if it's the main file
if __name__ == "__main__":
    print("initiallizing  bracket unit test")
    unittest.main(verbosity=2)
    #4 different verbosities, 2 as default