# Student Management System

## Overview

The **Student Management System** is a C-based program designed to manage student data effectively. This system uses **structures** and **dynamic memory allocation** to model and handle student information efficiently. Key functionalities include adding student details, managing subjects and scores, and evaluating grades and pass/fail statuses. 

## Features

- **Dynamic Memory Management**: All student and subject data are allocated dynamically on the heap using `malloc`.
- **Duplicate ID Safeguard**: Prevents the addition of students with existing IDs.
- **Scalable Storage**: Automatically expands array size when capacity is reached.
- **Comprehensive Student Data Handling**:
  - Automatic calculation of grades and average scores.
  - Pass/fail status evaluation.
- **CRUD Operations**: 
  - Add, edit, view, search, and categorize students by pass/fail status.
- **Enhanced UI**:
  - Features like `SetColor` and `gotoxy` improve usability and appearance.
  - Dynamic background color changes for a visually appealing interface.
- **Error Feedback**: Clear error messages for invalid operations.

## User Manual

### Using the Features

1. **Add a New Student**:
   - Choose "Add a Student" from the menu.
   - Input a unique student ID, name, subjects, and scores.
2. **Edit a Student**:
   - Select "Edit a Student" to modify subjects and scores for an existing student.
3. **View All Students**:
   - Display detailed information for all students by selecting this option.
4. **View One Student**:
   - Display detailed information for a specific student.
5. **Search for a Student**:
   - Input a student ID to view their details.
6. **Display Pass/Fail Lists**:
   - Categorize and display students based on their pass/fail status.

## Limitations and Potential Failures

- **Input Sensitivity**: 
  - Only integer inputs are accepted for IDs and scores.
  - Invalid inputs may cause program crashes. Error handling is in place to minimize this.

## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/your-repository-name.git
