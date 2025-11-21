--📜 Paper 3: Table & Data Generation Scripts

-- Create Customers Table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(50) NOT NULL,
    JoinDate DATE NOT NULL
);

-- Create Products Table
CREATE TABLE Products (
    ProductID INT PRIMARY KEY IDENTITY(1,1),
    ProductName VARCHAR(100) NOT NULL,
    Category VARCHAR(50),
    Price DECIMAL(10,2) NOT NULL,
    StockQuantity INT NOT NULL
);

-- Create Orders Table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY IDENTITY(1,1),
    CustomerID INT FOREIGN KEY REFERENCES Customers(CustomerID),
    ProductID INT FOREIGN KEY REFERENCES Products(ProductID),
    OrderDate DATE NOT NULL,
    Quantity INT NOT NULL,
    Price DECIMAL(10,2) NOT NULL, -- Price at time of order
    TotalOrderAmount DECIMAL(10,2) NOT NULL,
    OrderStatus VARCHAR(20) CHECK (OrderStatus IN ('Pending', 'Shipped', 'Delivered', 'Cancelled'))
);


--Question 1: List customers who have never placed any order.
SELECT
    C.CustomerID,
    C.Name,
    C.JoinDate
FROM Customers C
LEFT JOIN Orders O ON C.CustomerID = O.CustomerID
WHERE O.OrderID IS NULL;

--OR
SELECT * FROM Customers
WHERE CustomerID NOT IN (SELECT CustomerID FROM Orders)

--Question 2: List products ordered by more than 5 different customers.
SELECT P.ProductName,COUNT(DISTINCT O.CustomerID)
FROM Products P INNER JOIN Orders O
ON P.ProductID = O.ProductID
GROUP BY P.ProductName
HAVING COUNT(DISTINCT O.CustomerID) > 5

--Question 3: List customers whose first order was placed in 2024.
SELECT C.Name,MIN(O.OrderDate) AS FirstOrderDate
FROM Customers  C INNER JOIN Orders O
ON C.CustomerID = O.CustomerID
GROUP BY C.Name
HAVING MIN(O.OrderDate) >= '2024-01-01' AND
	MIN(O.OrderDate) < '2025-01-01'

--Question 4: List top 3 products with the highest total revenue.
SELECT TOP 3 P.ProductName,SUM(O.Quantity * O.Price) AS total_revenue
FROM Products P INNER JOIN Orders O
ON P.ProductID = O.ProductID
GROUP BY P.ProductName
ORDER BY SUM(O.Quantity * O.Price) DESC

--Question 5: Find the latest order placed for each customer.
SELECT C.Name , MAX(O.OrderDate) AS latest_order
FROM Customers C INNER JOIN Orders O
ON C.CustomerID = O.CustomerID
GROUP BY C.Name

--Question 6: List products that have been ordered but are currently out of stock.
SELECT ProductName,StockQuantity
FROM Products
WHERE StockQuantity = 0

--OR
SELECT P.ProductName,P.StockQuantity
FROM Products P JOIN Orders O
ON P.ProductID = O.ProductID
WHERE P.StockQuantity = 0

--Question 7: List customers who placed orders in more than one product category.
SELECT C.Name,COUNT(DISTINCT P.Category) AS UniqueCategoriesCount
FROM Customers C JOIN Orders O
ON C.CustomerID = O.CustomerID
JOIN Products P
ON P.ProductID = O.ProductID
GROUP BY C.Name
HAVING COUNT(DISTINCT P.Category) > 1

--Question 8: List products with no orders in the last 6 months.
SELECT P.ProductName
FROM Products AS P
WHERE P.ProductID NOT IN (
        SELECT O.ProductID
        FROM Orders AS O
        WHERE  O.OrderDate >= DATEADD(MONTH, -6, GETDATE())
    );

--Question 9: Find Customers having Same JoinDate.
SELECT JoinDate,Name 
FROM Customers
WHERE JoinDate IN(
	SELECT JoinDate FROM Customers
	GROUP BY JoinDate
	HAVING COUNT(*) > 1
	)
ORDER BY JoinDate,Name;

--Question 10: Find the product whose price is second highest.
SELECT * FROM Products
WHERE Price = (
	SELECT MAX(Price) AS SEC_LARGEST
	FROM Products
		WHERE Price < (SELECT MAX(Price) FROM Products)
) 