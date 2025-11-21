--Doctors
CREATE TABLE Doctors (
    DoctorID INT PRIMARY KEY IDENTITY(1,1),
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Email VARCHAR(100) UNIQUE,
    Specialization VARCHAR(100),
    Salary DECIMAL(10,2),
    HireDate DATE
);
--Patients
CREATE TABLE Patients (
    PatientID INT PRIMARY KEY IDENTITY(1,1),
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    BirthDate DATE,
    Gender CHAR(1),
    ContactNumber VARCHAR(15)
);
--Departments
CREATE TABLE Departmentss (
    DepartmentID INT PRIMARY KEY IDENTITY(1,1),
    DepartmentName VARCHAR(100) UNIQUE,
    Floor INT,
    HeadDoctorID INT FOREIGN KEY REFERENCES Doctors(DoctorID)
);
--Appointments
CREATE TABLE Appointments (
    AppointmentID INT PRIMARY KEY IDENTITY(1,1),
    PatientID INT FOREIGN KEY REFERENCES Patients(PatientID),
    DoctorID INT FOREIGN KEY REFERENCES Doctors(DoctorID),
    AppointmentDate DATETIME NOT NULL,
    Status VARCHAR(20)
);
--MedicalRecords
CREATE TABLE MedicalRecords (
    RecordID INT PRIMARY KEY IDENTITY(1,1),
    PatientID INT FOREIGN KEY REFERENCES Patients(PatientID),
    Diagnosis VARCHAR(255),
    Treatment VARCHAR(255),
    RecordDate DATE
);

--1.Patients without appointments in 2025.
SELECT * FROM Patients AS P
WHERE NOT EXISTS (
	SELECT 1 FROM Appointments AS A
	WHERE A.PatientID = P.PatientID AND YEAR(A.AppointmentDate) = 2025
)

--2.Top 2 highest earning doctors per departmenT
SELECT TOP 2 D.DepartmentName, DO.FirstName, DO.LastName, DO.Salary
FROM Doctors DO
JOIN Departmentss D ON DO.Specialization = D.DepartmentName
WHERE DO.Salary >= (
    SELECT Salary
    FROM Doctors D2
    WHERE D2.Specialization = DO.Specialization
	ORDER BY DO.Salary DESC
)
ORDER BY D.DepartmentName, DO.Salary DESC

--3.Departments with 15+ completed appointments in 2024.
SELECT D.DepartmentName, COUNT(*) AS CompletedCount
FROM Appointments A
JOIN Doctors DO ON A.DoctorID = DO.DoctorID
JOIN Departmentss D ON DO.Specialization = D.DepartmentName
WHERE A.Status = 'Completed' AND YEAR(A.AppointmentDate) = 2024
GROUP BY D.DepartmentName
HAVING COUNT(*) >= 15;

--4.Second highest salary doctor in Cardiology.
SELECT * FROM Doctors
WHERE Specialization = 'Cardiology'
AND Salary < (
    SELECT MAX(Salary)
    FROM Doctors
)
ORDER BY Salary DESC;

--5.Patients who visited 4+ doctors in 2024.
SELECT P.FirstName
FROM Patients P
JOIN Appointments A ON P.PatientID = A.PatientID
WHERE YEAR(A.AppointmentDate) = 2024
GROUP BY P.FirstName
HAVING COUNT(DISTINCT A.DoctorID) >= 4;

--6.Department with highest avg doctor salary.
SELECT TOP 1 D.DepartmentName, AVG(DO.Salary) AS AvgSal
FROM Doctors DO
JOIN Departmentss D ON DO.Specialization = D.DepartmentName
GROUP BY D.DepartmentName
ORDER BY AVG(DO.Salary) DESC

--7.Patients with more than 3 medical records.
SELECT P.FirstName
FROM Patients P
JOIN MedicalRecords M ON P.PatientID = M.PatientID
GROUP BY P.FirstName
HAVING COUNT(*) > 3

--8.Doctors who are department heads AND have appointments in 2025.

SELECT DO.FirstName
FROM Doctors DO
JOIN Departmentss D ON D.HeadDoctorID = DO.DoctorID
JOIN Appointments A ON A.DoctorID = DO.DoctorID
WHERE YEAR(A.AppointmentDate) = 2025
GROUP BY DO.FirstName

--9.Patients older than avg patient age.
SELECT P.*
FROM Patients P
WHERE DATEDIFF(YEAR, P.BirthDate, GETDATE()) > (
    SELECT AVG(DATEDIFF(YEAR, BirthDate, GETDATE())) FROM Patients
);

--10.Doctors with no appointments in January 2025.
SELECT D.*
FROM Doctors D
WHERE D.DoctorID NOT IN (
    SELECT DoctorID FROM Appointments
    WHERE MONTH(AppointmentDate) = 1 AND YEAR(AppointmentDate) = 2025
)