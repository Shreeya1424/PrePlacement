--📜 Paper 6: Table & Data Generation Scripts

-- Create Customers Table
CREATE TABLE Customers (
    CustomerID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    JoinDate DATE NOT NULL
);

-- Create Products Table
CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    ProductName VARCHAR(100) NOT NULL,
    Category VARCHAR(50) NOT NULL,
    Price DECIMAL(10,2) NOT NULL,
    StockQuantity INT NOT NULL
);

-- Create Orders Table
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    CustomerID INT FOREIGN KEY REFERENCES Customers(CustomerID),
    ProductID INT FOREIGN KEY REFERENCES Products(ProductID),
    OrderDate DATE NOT NULL,
    Quantity INT NOT NULL,
    Price DECIMAL(10,2) NOT NULL,       -- Price at time of order
    Amount DECIMAL(10,2) NOT NULL,     -- Total = Quantity * Price
    ShippedDate DATE NULL,
    OrderStatus VARCHAR(20) CHECK (OrderStatus IN ('Pending', 'Shipped', 'Delivered', 'Cancelled'))
);

-- Create Payments Table
CREATE TABLE Payments (
    PaymentID INT PRIMARY KEY IDENTITY(1,1),
    OrderID INT FOREIGN KEY REFERENCES Orders(OrderID),
    PaymentDate DATE NOT NULL,
    PaymentAmount DECIMAL(10,2) NOT NULL
);


--Question 1: List Customers with total outstanding amount.
SELECT C.Name,SUM(O.Amount) - SUM(ISNULL(P.PaymentAmount, 0)) AS OutstandingAmount
FROM Customers C
LEFT JOIN Orders O 
    ON C.CustomerID = O.CustomerID
LEFT JOIN Payments P 
    ON O.OrderID = P.OrderID
GROUP BY C.CustomerID, C.Name

--Question 2: List Customers who placed more than 2 orders in a single day of a same product.
SELECT C.Name, P.ProductName,  O.OrderDate,
COUNT(O.OrderID) AS TotalOrders
FROM Orders O JOIN Customers C 
ON O.CustomerID = C.CustomerID
JOIN Products P 
ON O.ProductID = P.ProductID
GROUP BY C.Name, P.ProductName, O.OrderDate
HAVING COUNT(O.OrderID) > 2

--Question 3: List Orders which are delivered but payment not received.
SELECT C.Name AS CustomerName,P.ProductName,O.OrderID,O.OrderDate,O.Amount
FROM Orders O JOIN Customers C 
ON O.CustomerID = C.CustomerID
JOIN Products P 
ON O.ProductID = P.ProductID
WHERE O.OrderStatus = 'Delivered'
  AND NOT EXISTS (
    SELECT 1
    FROM Payments PM
    WHERE PM.OrderID = O.OrderID
  )

--Question 4: List All Products whose price is more than Product "Keyboard".
SELECT ProductName,Price
FROM Products
WHERE Price > (
    SELECT Price
    FROM Products
    WHERE ProductName = 'Keyboard'
)

--Question 5: List Customers which have not placed a single order.
SELECT C.CustomerID,C.Name,C.JoinDate
FROM Customers C
LEFT JOIN Orders O
ON C.CustomerID = O.CustomerID
WHERE O.OrderID IS NULL

--Question 6: List Products where StockQuantity is less than Pending Order Total Quantity.
WITH PendingQuantities AS (
    SELECT ProductID,SUM(Quantity) AS TotalPending
    FROM Orders
    WHERE OrderStatus = 'Pending'
    GROUP BY ProductID
)
SELECT P.ProductName,P.StockQuantity,PQ.TotalPending AS PendingOrderQuantity
FROM Products P JOIN PendingQuantities PQ 
ON P.ProductID = PQ.ProductID
WHERE P.StockQuantity < PQ.TotalPending

--Question 7: Category Wise Sales Summary (Include all the category even if with zero orders).
SELECT P.Category,
    COUNT(DISTINCT O.CustomerID) AS Total_Customers,
    COUNT(O.OrderID) AS Total_Orders,
    COUNT(DISTINCT P.ProductID) AS Total_Products,
    ISNULL(SUM(O.Quantity), 0) AS Total_Quantity,
    ISNULL(SUM(O.Amount), 0) AS Total_Order_Amount
FROM Products P
LEFT JOIN Orders O ON P.ProductID = O.ProductID
GROUP BY P.Category;

--Question 8: List Customer with Order detail who has placed order of same product again within 7 days.
SELECT 
    C.Name AS CustomerName,
    P.ProductName,
    O1.OrderDate AS PrevOrderDate,
    O2.OrderDate AS CurrentOrderDate,
    DATEDIFF(DAY, O1.OrderDate, O2.OrderDate) AS DaysBetween
FROM Orders O1
JOIN Orders O2 
ON O1.OrderID = O2.OrderID   
JOIN Customers C 
ON O1.CustomerID = C.CustomerID
JOIN Products P 
ON O1.ProductID = P.ProductID
WHERE 
    O1.CustomerID = O2.CustomerID
    AND O1.ProductID = O2.ProductID
    AND O2.OrderDate > O1.OrderDate
    AND DATEDIFF(DAY, O1.OrderDate, O2.OrderDate) <= 7;

--Question 9: Product Wise Total Orders, Lowest Price, Highest Price & Average Price.
SELECT
    P.Category,
    P.ProductName AS Product,
    COUNT(O.OrderID) AS TotalOrders,
    MIN(O.Price) AS LowestPrice,
    MAX(O.Price) AS HighestPrice,
    AVG(O.Price) AS AveragePrice
FROM Orders O
JOIN Products P ON O.ProductID = P.ProductID
GROUP BY P.Category, P.ProductName
ORDER BY P.Category, Product

--Question 10: List Date Wise Pending Order and Pending Ordered Quantity Product Wise between fromDate and toDate.
DECLARE @fromDate DATE = '2025-04-01';
DECLARE @toDate DATE = '2025-04-03';

SELECT
    O.OrderDate AS Date,
    P.ProductName AS Product,
    COUNT(O.OrderID) AS TotalPendingOrders,
    SUM(O.Quantity) AS TotalPendingQuantity
FROM Orders O
JOIN Products P ON O.ProductID = P.ProductID
WHERE
    O.OrderStatus = 'Pending'
    AND O.OrderDate BETWEEN @fromDate AND @toDate
GROUP BY O.OrderDate, P.ProductName
ORDER BY Date, Product;