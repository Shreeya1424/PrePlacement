--University Database Schema and Queries

--Departments
CREATE TABLE Departments (
    DepartmentID INT PRIMARY KEY IDENTITY(1,1),
    DepartmentName VARCHAR(100) NOT NULL UNIQUE,
    Budget DECIMAL(12,2) NOT NULL DEFAULT 0.00
);
--Courses
CREATE TABLE Courses (
    CourseID INT PRIMARY KEY IDENTITY(1,1),
    CourseCode VARCHAR(10) NOT NULL UNIQUE,
    CourseName VARCHAR(150) NOT NULL,
    DepartmentID INT NOT NULL FOREIGN KEY REFERENCES Departments(DepartmentID),
    Credits INT NOT NULL CHECK (Credits > 0),
    LeadProfessor VARCHAR(100) NULL
);
--Students
CREATE TABLE Students (
    StudentID INT PRIMARY KEY IDENTITY(1,1),
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    EnrollmentDate DATE NOT NULL,
    GPA DECIMAL(3,2) NULL CHECK (GPA BETWEEN 0.00 AND 4.00)
);

--1.List all courses from departments that have a budget greater than 1 million.
SELECT C.CourseCode,C.CourseName,D.DepartmentName,D.Budget
FROM Departments D JOIN Courses C
ON D.DepartmentID = C.DepartmentID
WHERE D.Budget >1000000

--2.List all departments along with the number of courses they offer.
SELECT D.DepartmentName,COUNT(C.CourseID) AS CourseCount
FROM Departments D JOIN Courses C
ON D.DepartmentID = C.DepartmentID
GROUP BY D.DepartmentName

--3.List all departments that offer more than 3 courses.
SELECT D.DepartmentName,COUNT(C.CourseID) AS TotalCourse
FROM Departments D JOIN Courses C
ON D.DepartmentID = C.DepartmentID
GROUP BY D.DepartmentName
HAVING COUNT(C.CourseID) > 3

--4.Find the course with the second-highest credit hours in the 'Computer Science' department.
SELECT TOP 1 C.CourseName,C.Credits
FROM Courses C JOIN Departments D
ON C.DepartmentID = D.DepartmentID
WHERE D.DepartmentName = 'Computer Science' AND
	C.Credits <
	(
	SELECT MAX(Credits) 
	FROM Courses
	WHERE DepartmentID = D.DepartmentID
	)
ORDER BY C.Credits DESC

--5.List all students whose GPA is above the average GPA of all students.
SELECT * FROM Students
WHERE GPA > (SELECT AVG(GPA) FROM Students)

--6.Find the department with the highest number of courses.
SELECT TOP 1 D.DepartmentName,COUNT(C.CourseID) AS TotalCourse
FROM Departments D JOIN Courses C
ON D.DepartmentID = C.DepartmentID
GROUP BY D.DepartmentName
ORDER BY COUNT(C.CourseID) DESC

--7.List students who enrolled on the same enrollment date as at least one other student.
SELECT * FROM Students
WHERE EnrollmentDate IN(
	SELECT EnrollmentDate 
	FROM Students
	GROUP BY EnrollmentDate
	HAVING COUNT(*)>1
)
ORDER BY EnrollmentDate

--8.Find all courses where the LeadProfessor name contains the word 'Head'.
SELECT * FROM Courses
WHERE LeadProfessor LIKE '%Head%'

--9.Retrieve courses offered by departments whose budget is above the average department budget.
SELECT C.CourseName, D.DepartmentName, D.Budget
FROM Courses C
JOIN Departments D ON C.DepartmentID = D.DepartmentID
WHERE D.Budget > (SELECT AVG(Budget) FROM Departments)

--10.List students who enrolled after the earliest enrollment date in the table.
SELECT * FROM Students
WHERE EnrollmentDate > (
	SELECT MIN(EnrollmentDate)
	FROM Students
)

