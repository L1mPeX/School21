#!/usr/bin/env python3

import os
import subprocess

class GrepTester:
    def __init__(self):
        self.s21_grep = "./s21_grep"
        self.gnu_grep = "grep"
        self.output_prefix = "TEST-"
        self.output_suffix = ".tmp"
        
        # Your original test configuration
        self.template = '[0-9]'
        self.test_file = './TEST-SUITE/TEST-FILE_001'
        self.test_template = './TEST-SUITE/TEST-TEMPLATE'
        
        # Your original test cases
        self.test_cases = [
            f'-e {self.template} -e {self.test_template} {self.test_file}',
            f'-f {self.test_template} -e {self.template} {self.test_file}',
            f'-f {self.test_template} s21_grep.c s21_grep.h',
            f'-vf {self.test_template} {self.test_file}',
            f'-cf {self.test_template} {self.test_file}',
            f'-lf {self.test_template} {self.test_file}',
            f'-nf {self.test_template} {self.test_file}',
            f'-hf {self.test_template} {self.test_file}',
            f'-h if {self.test_file} s21_grep.h',
            f'-ie {self.template} {self.test_file}',
            f'-ve {self.template} {self.test_file}',
            f'-ce {self.template} {self.test_file}',
            f'-le {self.template} {self.test_file}',
            f'-ne {self.template} {self.test_file}',
            f'-he {self.template} {self.test_file}',
            f'-se {self.template} {self.test_file}',
            f'-oe {self.template} {self.test_file}',
            f'-iv {self.template} {self.test_file}',
            f'-ic {self.template} {self.test_file}',
            f'-il {self.template} {self.test_file}',
            f'-in {self.template} {self.test_file}',
            f'-ih {self.template} {self.test_file}',
            f'-is {self.template} {self.test_file}',
            f'-io {self.template} {self.test_file}',
            f'-vc {self.template} {self.test_file}',
            f'-vl {self.template} {self.test_file}',
            f'-vn {self.template} {self.test_file}',
            f'-vh {self.template} {self.test_file}',
            f'-vs {self.template} {self.test_file}',
            f'-vo {self.template} {self.test_file}',
            f'-cl {self.template} {self.test_file}',
            f'-cn {self.template} {self.test_file}',
            f'-ch {self.template} {self.test_file}',
            f'-cs {self.template} {self.test_file}',
            f'-co {self.template} {self.test_file}',
            f'-ln {self.template} {self.test_file}',
            f'-lh {self.template} {self.test_file}',
            f'-ls {self.template} {self.test_file}',
            f'-lo {self.template} {self.test_file}',
            f'-nh {self.template} {self.test_file}',
            f'-ns {self.template} {self.test_file}',
            f'-no {self.template} {self.test_file}',
            f'-hs {self.template} {self.test_file}',
            f'-ho {self.template} {self.test_file}',
            f'-l {self.template} {self.test_file}',
            f'-v {self.template} {self.test_file}',
            f'-c {self.template} {self.test_file}',
            f'-n {self.template} {self.test_file}',
            f'-o {self.template} {self.test_file}',
            f'[0-9] {self.test_file}',
            f'-i RY {self.test_file}'
        ]
        
        self.passed = 0
        self.failed = 0
        self.failed_tests = []

    def run_command(self, command):
        try:
            result = subprocess.run(command, shell=True, 
                                  stdout=subprocess.PIPE, 
                                  stderr=subprocess.PIPE,
                                  text=True)
            return result.stdout, result.stderr, result.returncode
        except subprocess.CalledProcessError as e:
            return e.stdout, e.stderr, e.returncode

    def compare_outputs(self, s21_out, grep_out, test_case):
        if s21_out == grep_out:
            self.passed += 1
            print(f"PASS: {test_case}")
            return True
        else:
            self.failed += 1
            self.failed_tests.append(test_case)
            print(f"FAIL: {test_case}")
            
            # Simple diff implementation without external libs
            print("\nDifferences found:")
            s21_lines = s21_out.splitlines()
            grep_lines = grep_out.splitlines()
            
            max_lines = max(len(s21_lines), len(grep_lines))
            for i in range(max_lines):
                s21_line = s21_lines[i] if i < len(s21_lines) else ""
                grep_line = grep_lines[i] if i < len(grep_lines) else ""
                
                if s21_line != grep_line:
                    print(f"Line {i+1}:")
                    print(f"Expected: {grep_line}")
                    print(f"Got:      {s21_line}")
                    print()
            
            return False

    def run_test_case(self, test_case):
        s21_cmd = f"{self.s21_grep} {test_case}"
        grep_cmd = f"{self.gnu_grep} {test_case}"
        
        s21_out, s21_err, s21_rc = self.run_command(s21_cmd)
        grep_out, grep_err, grep_rc = self.run_command(grep_cmd)
        
        # Compare return codes first
        if s21_rc != grep_rc:
            self.failed += 1
            self.failed_tests.append(test_case)
            print(f"FAIL: {test_case} (Different return codes)")
            print(f"s21_grep returned {s21_rc}, grep returned {grep_rc}")
            if s21_err:
                print(f"s21_grep errors:\n{s21_err}")
            return False
        
        return self.compare_outputs(s21_out, grep_out, test_case)

    def generate_report(self):
        print("\nTest Summary:")
        print(f"Total tests: {len(self.test_cases)}")
        print(f"Passed: {self.passed}")
        print(f"Failed: {self.failed}")
        
        if self.failed > 0:
            print("\nFailed tests:")
            for test in self.failed_tests:
                print(f"- {test}")
        
        return self.failed == 0

    def cleanup(self):
        # Remove any temporary files if created
        pass

    def run_all_tests(self):
        print("Starting test suite...\n")
        for test_case in self.test_cases:
            self.run_test_case(test_case)
        
        success = self.generate_report()
        self.cleanup()
        return success

if __name__ == "__main__":
    tester = GrepTester()
    exit(0 if tester.run_all_tests() else 1)