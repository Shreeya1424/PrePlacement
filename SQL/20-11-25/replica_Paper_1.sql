-- Table: Members
CREATE TABLE Members (
MemberID INT PRIMARY KEY IDENTITY(1,1), -- PRIMARY KEY with auto-increment [cite: 4]
FullName VARCHAR(100),
Email VARCHAR(100) UNIQUE, -- UNIQUE constraint [cite: 6]
JoinDate DATE,
MembershipType VARCHAR(20)
);
-- Table: Books
CREATE TABLE Books (
BookID INT PRIMARY KEY IDENTITY(1,1), -- PRIMARY KEY with auto-increment [cite: 12]
Title VARCHAR(150),
Author VARCHAR(100),
Genre VARCHAR(50),
PublishedYear INT,
TotalCopies INT,
AvailableCopies INT
)
-- Table: BorrowRecords
CREATE TABLE BorrowRecords (
BorrowID INT PRIMARY KEY IDENTITY(1,1), -- PRIMARY KEY with auto-increment [cite: 22]
MemberID INT FOREIGN KEY REFERENCES Members(MemberID), -- FOREIGN KEY to Members[cite: 23]
BookID INT FOREIGN KEY REFERENCES Books(BookID), -- FOREIGN KEY to Books [cite: 24]
BorrowDate DATE,
ReturnDate DATE -- NULL if not yet returned [cite: 26]
);

-- Table: Fines

CREATE TABLE Fines (
FineID INT PRIMARY KEY IDENTITY(1,1), -- PRIMARY KEY with auto-increment [cite: 30]
BorrowID INT FOREIGN KEY REFERENCES BorrowRecords(BorrowID), -- FOREIGN KEY to BorrowRecords [cite: 31]
FineAmount DECIMAL(10,2),
PaidStatus VARCHAR(20) -- e.g., 'Unpaid', 'Paid'
);



--1. Display all members who joined in the year 2024.
SELECT * FROM Members 
WHERE JoinDate >= '2024-01-01'AND
	JoinDate < '2025-01-01'

--2. Show all books written by a specific author (e.g., "J.K. Rowling").
SELECT * FROM Books
WHERE Author = 'J.K. Rowling'

--3. List all books that have zero available copies.
SELECT * FROM Books
WHERE TotalCopies = 0

--4. Find all borrow records where the book has not been returned yet (ReturnDate IS NULL).
SELECT B.Title,BR.* 
FROM Books B JOIN BorrowRecords BR
ON B.BookID = BR.BookID
WHERE BR.ReturnDate IS NULL

--5. Show all members who have borrowed at least one book.
SELECT M.FullName , COUNT(BR.BorrowID)
FROM Members M JOIN BorrowRecords BR
ON M.MemberID = BR.MemberID
GROUP BY M.FullName
HAVING COUNT(BR.BorrowID) >=1
--6. List all books borrowed by a specific member (using MemberID).
SELECT B.Title,BR.* 
FROM Books B JOIN BorrowRecords BR
ON B.BookID = BR.BookID
WHERE BR.MemberID = 2

--7. Count how many books are available in each genre.
SELECT Genre, COUNT(*) AS TotalBooks
FROM Books
GROUP BY Genre;

--8. Show the total number of books borrowed (all records count).
SELECT COUNT(*) AS TotalBorrowed
FROM BorrowRecords

--9. Display members who have unpaid fines.
SELECT M.FullName,BR.MemberID,F.PaidStatus
FROM Members M JOIN BorrowRecords BR
ON M.MemberID = BR.MemberID
JOIN Fines F
ON BR.BorrowID = F.BorrowID
WHERE F.PaidStatus ='unpaid'

--10. Get the total fine amount for each borrow record.
SELECT BorrowID,SUM(FineAmount) AS TotalFine
FROM Fines
GROUP BY BorrowID

--11. Show the most recently borrowed book (based on BorrowDate).
SELECT MAX(BorrowDate) FROM BorrowRecords

--12. List all members along with the number of books they have borrowed.
SELECT M.MemberID,M.FullName,COUNT(BR.BorrowID) AS TotalBorrowed
FROM Members M LEFT JOIN BorrowRecords BR 
ON M.MemberID = BR.MemberID
GROUP BY M.MemberID, M.FullName

--13. Display books borrowed in the last 30 days.
SELECT B.Title,BR.BorrowDate
FROM BorrowRecords BR JOIN Books B 
ON BR.BookID = B.BookID
WHERE BR.BorrowDate >= DATEADD(DAY, -30, GETDATE())

--14. Show members who have borrowed more than one book.
SELECT M.FullName,COUNT(BR.BorrowID) AS TotalBorrowed
FROM Members M JOIN BorrowRecords BR 
ON M.MemberID = BR.MemberID
GROUP BY M.MemberID, M.FullName
HAVING COUNT(BR.BorrowID) > 1

--15. List all books that have never been borrowed.
SELECT B.Title
FROM Books B LEFT JOIN BorrowRecords BR 
ON B.BookID = BR.BookID
WHERE BR.BookID IS NULL