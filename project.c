-- Create Database
CREATE DATABASE IF NOT EXISTS lms;
USE lms;

-- Table: authors
CREATE TABLE authors (
    author_id INT PRIMARY KEY,
    author_name VARCHAR(100),
    author_address VARCHAR(255)
);

-- Sample data for authors
INSERT INTO authors VALUES
(1, 'J.K. Rowling', 'London, UK'),
(2, 'George R.R. Martin', 'Bayonne, USA'),
(3, 'Rabindranath Tagore', 'Kolkata, India');

-- Table: publisher
CREATE TABLE publisher (
    publisher_id INT PRIMARY KEY,
    name VARCHAR(100),
    address VARCHAR(255)
);

-- Sample data for publisher
INSERT INTO publisher VALUES
(1, 'Penguin Random House', 'New York, USA'),
(2, 'HarperCollins', 'London, UK'),
(3, 'Ananda Publishers', 'Kolkata, India');

-- Table: books
CREATE TABLE books (
    book_id INT PRIMARY KEY,
    book_title VARCHAR(200),
    author_id INT,
    publisher_id INT,
    no_of_copies INT,
    FOREIGN KEY (author_id) REFERENCES authors(author_id),
    FOREIGN KEY (publisher_id) REFERENCES publisher(publisher_id)
);

-- Sample data for books
INSERT INTO books VALUES
(1, 'Harry Potter and the Sorcerer''s Stone', 1, 1, 10),
(2, 'A Game of Thrones', 2, 2, 5),
(3, 'Gitanjali', 3, 3, 8);

-- Table: borrowers
CREATE TABLE borrowers (
    borrower_id INT PRIMARY KEY,
    firstname VARCHAR(50),
    lastname VARCHAR(50),
    address VARCHAR(255),
    email VARCHAR(100),
    phone VARCHAR(15),
    department VARCHAR(100)
);

-- Sample data for borrowers
INSERT INTO borrowers VALUES
(1, 'John', 'Doe', '123 Main St', 'john@example.com', '1234567890', 'CSE'),
(2, 'Jane', 'Smith', '456 Elm St', 'jane@example.com', '0987654321', 'EEE'),
(3, 'Rahul', 'Roy', '789 Park Ave', 'rahul@example.com', '1112223334', 'ME');

-- Table: booking
CREATE TABLE booking (
    booking_id INT PRIMARY KEY,
    book_id INT,
    borrower_id INT,
    booking_date DATE,
    available_date DATE,
    FOREIGN KEY (book_id) REFERENCES books(book_id),
    FOREIGN KEY (borrower_id) REFERENCES borrowers(borrower_id)
);

-- Sample data for booking
INSERT INTO booking VALUES
(1, 1, 1, '2025-05-01', '2025-05-03'),
(2, 2, 2, '2025-05-02', '2025-05-04'),
(3, 3, 3, '2025-05-01', '2025-05-05');

-- Table: borrow_book
CREATE TABLE borrow_book (
    id INT PRIMARY KEY,
    book_id INT,
    borrower_id INT,
    borrowing_date DATE,
    duedate DATE,
    FOREIGN KEY (book_id) REFERENCES books(book_id),
    FOREIGN KEY (borrower_id) REFERENCES borrowers(borrower_id)
);

-- Sample data for borrow_book
INSERT INTO borrow_book VALUES
(1, 1, 1, '2025-05-03', '2025-05-17'),
(2, 2, 2, '2025-05-04', '2025-05-18');

-- Table: fine
CREATE TABLE fine (
    fine_id INT PRIMARY KEY,
    borrow_id INT,
    fine_amount DECIMAL(6,2),
    fine_date DATE,
    FOREIGN KEY (borrow_id) REFERENCES borrow_book(id)
);

-- Sample data for fine
INSERT INTO fine VALUES
(1, 1, 50.00, '2025-05-18'),
(2, 2, 25.00, '2025-05-19');
