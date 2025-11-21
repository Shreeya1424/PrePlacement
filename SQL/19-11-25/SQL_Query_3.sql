-- ==========================================
-- 1. TABLE CREATION
-- ==========================================

-- Users Table
CREATE TABLE Userss (
    UserID INT PRIMARY KEY IDENTITY(1,1),
    UserName VARCHAR(100) NOT NULL,
    JoinDate DATE NOT NULL,
    Country VARCHAR(50)
);

-- Pages Table
CREATE TABLE Pages (
    PageID INT PRIMARY KEY IDENTITY(1,1),
    PageURL VARCHAR(200) NOT NULL,
    PageType VARCHAR(50)
);

-- Page_Views Table
CREATE TABLE Page_Views (
    ViewID INT PRIMARY KEY IDENTITY(1,1),
    UserID INT FOREIGN KEY REFERENCES Userss(UserID),
    PageID INT FOREIGN KEY REFERENCES Pages(PageID),
    ViewTimestamp DATETIME NOT NULL
);

-- Events Table
CREATE TABLE Events (
    EventID INT PRIMARY KEY IDENTITY(1,1),
    ViewID INT FOREIGN KEY REFERENCES Page_Views(ViewID),
    EventName VARCHAR(50),
    EventValue INT
);

-- ==========================================
-- 2. INSERT SAMPLE DATA (5 RECORDS EACH)
-- ==========================================

-- Insert Users (5 Records)
INSERT INTO Userss (UserName, JoinDate, Country)
VALUES 
('Alice', '2023-01-10', 'USA'),
('Rohan', '2023-02-15', 'India'),
('Maria', '2023-03-20', 'Brazil'),
('John', '2023-04-05', 'Canada'),
('Kavita', '2023-05-12', 'India');

-- Insert Pages (5 Records)
INSERT INTO Pages (PageURL, PageType)
VALUES
('/', 'Home'),
('/product/101', 'Product'),
('/product/202', 'Product'),
('/cart', 'Cart'),
('/checkout', 'Checkout');

-- Insert Page_Views (5 Records)
INSERT INTO Page_Views (UserID, PageID, ViewTimestamp)
VALUES
(1, 1, '2023-10-21 10:15:00'),
(2, 2, '2023-10-21 10:17:30'),
(3, 3, '2023-10-21 10:20:10'),
(4, 4, '2023-10-21 10:25:55'),
(5, 5, '2023-10-21 10:30:45');

-- Insert Events (5 Records)
INSERT INTO Events (ViewID, EventName, EventValue)
VALUES
(1, 'page_load', NULL),
(2, 'add_to_cart', 1),
(3, 'play_video', 30),
(4, 'click_buy', NULL),
(5, 'rating', 5);

--Section 1: Medium-Hard Queries
--1. Top "Cart-Adders": Find the user (UserName) who has triggered the 'addto_cart'event the most times.
SELECT TOP 1 U.UserName, COUNT(*) AS AddToCartCount
FROM Events E
JOIN Page_Views PV ON E.ViewID = PV.ViewID
JOIN Userss U ON PV.UserID = U.UserID
WHERE E.EventName = 'add_to_cart'
GROUP BY U.UserName
ORDER BY AddToCartCount DESC;

--2. Most Viewed Page: Find the PageURL that has the most total Page_Views.
SELECT TOP 1 P.PageURL, COUNT(*) AS TotalViews
FROM Page_Views PV
JOIN Pages P ON PV.PageID = P.PageID
GROUP BY P.PageURL
ORDER BY TotalViews DESC;

--3. Country Activity: List the total number of page views and unique users for eachCountry.
SELECT 
    U.Country,
    COUNT(PV.ViewID) AS TotalPageViews,
    COUNT(DISTINCT U.UserID) AS UniqueUsers
FROM Userss U
LEFT JOIN Page_Views PV ON U.UserID = PV.UserID
GROUP BY U.Country;

--4. Bounced Users: Find all users who have only _ever viewed one page (i.e., theirtotal Page_Views count is 1).
SELECT U.UserID, U.UserName
FROM Userss U
JOIN Page_Views PV ON U.UserID = PV.UserID
GROUP BY U.UserID, U.UserName
HAVING COUNT(PV.ViewID) = 1;

--5. "Leaky" Cart: Find the PageURL of all 'Product' pages where an 'addto_cart' eventhas _never occurred.
SELECT P.PageURL
FROM Pages P
LEFT JOIN Page_Views PV ON P.PageID = PV.PageID
LEFT JOIN Events E 
    ON PV.ViewID = E.ViewID 
    AND E.EventName = 'add_to_cart'
WHERE P.PageType = 'Product'
GROUP BY P.PageURL
HAVING COUNT(E.EventID) = 0;

--6. "Buy" Button Mismatch: List all pages (PageURL) where a 'clickbuy' event was triggered, but the PageType was _not 'Checkout'.
SELECT DISTINCT P.PageURL
FROM Events E
JOIN Page_Views PV ON E.ViewID = PV.ViewID
JOIN Pages P ON PV.PageID = P.PageID
WHERE E.EventName = 'click_buy'
  AND P.PageType <> 'Checkout';

--7. The "Lurkers": Find users who have more than 10 'Article' page views but havenever viewed a 'Product' page.
SELECT U.UserID, U.UserName
FROM Userss U
JOIN Page_Views PV ON U.UserID = PV.UserID
JOIN Pages P ON PV.PageID = P.PageID
GROUP BY U.UserID, U.UserName
HAVING 
    SUM(CASE WHEN P.PageType = 'Article' THEN 1 ELSE 0 END) > 10
    AND SUM(CASE WHEN P.PageType = 'Product' THEN 1 ELSE 0 END) = 0;

--8. Orphaned Events: Find the EventName and count of all events that are associated with a ViewID that no longer exists in the Page_Views table.
SELECT 
    E.EventName,
    COUNT(*) AS OrphanedCount
FROM Events E
LEFT JOIN Page_Views PV ON E.ViewID = PV.ViewID
WHERE PV.ViewID IS NULL
GROUP BY E.EventName;
