#!/usr/bin/env python3

import os
import subprocess
from itertools import combinations_with_replacement

class CatTester:
    def __init__(self):
        self.s21_cat = "./s21_cat"
        self.gnu_cat = "cat"
        self.output_prefix = "TEST-"
        self.output_suffix = ".tmp"
        
        # Test files
        self.test_files = [
            'TEST-SUITE/TEST-FILE_002',
            # Add more test files as needed
        ]
        
        # Flags to test
        self.flags = {
            '-b',
            '-e',
            '-n', 
            '-s',
            '-v',
            '-t'
        }
        
        # Generate all flag combinations
        self.test_cases = []
        self.generate_test_cases()
        
        self.passed = 0
        self.failed = 0
        self.failed_tests = []

    def generate_test_cases(self):
        # Generate all possible flag combinations
        max_flags = len(self.flags)
        for r in range(1, max_flags + 1):
            for combo in combinations_with_replacement(self.flags, r):
                # Convert to set to remove duplicates, then back to tuple
                unique_flags = tuple(set(combo))
                for test_file in self.test_files:
                    self.test_cases.append(f"{' '.join(unique_flags)} {test_file}")
        
        # Also add cases with no flags
        for test_file in self.test_files:
            self.test_cases.append(test_file)

    def run_command(self, command):
        try:
            result = subprocess.run(command, shell=True, 
                                   stdout=subprocess.PIPE, 
                                   stderr=subprocess.PIPE,
                                   text=True)
            return result.stdout, result.stderr, result.returncode
        except subprocess.CalledProcessError as e:
            return e.stdout, e.stderr, e.returncode

    def compare_outputs(self, s21_out, cat_out, test_case):
        if s21_out == cat_out:
            self.passed += 1
            print(f"PASS: {test_case}")
            return True
        else:
            self.failed += 1
            self.failed_tests.append(test_case)
            print(f"FAIL: {test_case}")
            
            # Simple diff implementation
            s21_lines = s21_out.splitlines()
            cat_lines = cat_out.splitlines()
            
            max_lines = max(len(s21_lines), len(cat_lines))
            for i in range(max_lines):
                s21_line = s21_lines[i] if i < len(s21_lines) else ""
                cat_line = cat_lines[i] if i < len(cat_lines) else ""
                
                if s21_line != cat_line:
                    print(f"Line {i+1}:")
                    print(f"Expected: {cat_line}")
                    print(f"Got:      {s21_line}")
                    print()
            
            return False

    def run_test_case(self, test_case):
        s21_cmd = f"{self.s21_cat} {test_case}"
        cat_cmd = f"{self.gnu_cat} {test_case}"
        
        s21_out, s21_err, s21_rc = self.run_command(s21_cmd)
        cat_out, cat_err, cat_rc = self.run_command(cat_cmd)
        
        # Compare return codes first
        if s21_rc != cat_rc:
            self.failed += 1
            self.failed_tests.append(test_case)
            print(f"FAIL: {test_case} (Different return codes)")
            print(f"s21_cat returned {s21_rc}, cat returned {cat_rc}")
            if s21_err:
                print(f"s21_cat errors:\n{s21_err}")
            return False
        
        return self.compare_outputs(s21_out, cat_out, test_case)

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
    tester = CatTester()
    exit(0 if tester.run_all_tests() else 1)