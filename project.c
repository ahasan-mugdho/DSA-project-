-- Create the table
CREATE TABLE student (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    roll INT,
    city VARCHAR(100),
    dept_id INT,
    phone VARCHAR(15),
	FOREIGN KEY(dept_id)REFERENCES department(dept_id)
);

-- Insert 5 sample values
INSERT INTO student (id, name, roll, city, dept_id, phone) VALUES
(1, 'Antor', 101, 'Dhaka', 10, '1234567890'),
(2, 'Sobuj', 102, 'Barishal', 20, '2345678901'),
(3, 'Milon', 103, 'Dhaka', 10, '3456789012'),
(4, 'Rahim', 104, 'Khulna', 30, '4567890123'),
(5, 'Karim', 105, 'Barishal', 20, '5678901234');
CREATE TABLE department (
    id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);
INSERT INTO department (id, name) VALUES
(1, 'CSE'),
(2, 'Math'),
(3, 'CSE'),
(4, 'Math');-- Create the table
CREATE TABLE student (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    roll INT,
    city VARCHAR(100),
    dept_id INT,
    phone VARCHAR(15),
	FOREIGN KEY(dept_id)REFERENCES department(dept_id)
);

-- Insert 5 sample values
INSERT INTO student (id, name, roll, city, dept_id, phone) VALUES
(1, 'Antor', 101, 'Dhaka', 10, '1234567890'),
(2, 'Sobuj', 102, 'Barishal', 20, '2345678901'),
(3, 'Milon', 103, 'Dhaka', 10, '3456789012'),
(4, 'Rahim', 104, 'Khulna', 30, '4567890123'),
(5, 'Karim', 105, 'Barishal', 20, '5678901234');
CREATE TABLE department (
    id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);
INSERT INTO department (id, name) VALUES
(1, 'CSE'),
(2, 'Math'),
(3, 'CSE'),
(4, 'Math');
