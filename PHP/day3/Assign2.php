<?php
    class Author{
        private string $name;
        private string $email;
        private string $gender;

        public function __construct(string $name,string $email,string $gender){
            $this->name= $name;
            $this->email=$email;
            $this->setGender($gender);
        }

        function getName():string{
            return $this->name;
        }
        function getEmail():string{
            return $this->email;
        }
        function getGender():string{
            return $this->gender;
        }
        function setGender(string $gender):void{
            if($gender == "m" || $gender == "f"){
                $this->gender=$gender;
            }else{
                throw new InvalidArgumentException("Set the right gender.");
            }
        }
        public function __toString():string{
            return "Author(name={$this->name}, email={$this->email}, gender={$this->gender})";
        }
    }
    class Book{
        private string $bookName;
        private array $authors;
        private float $price;
        private int $qty;

        function __construct(string $bookName,array $authors,float $price, int $qty)
        {
            $this->bookName=$bookName;
            $this->authors=$authors;
            $this->price=$price;
            $this->qty=$qty;
        }
        function getName():string{
            return $this->bookName;
        }
        function getAuthor():array{
            return $this->authors;
        }
        function getPrice():float{
            return $this->price;
        }
        function getQty():int{
            return $this->qty;
        }
        function setPrice(float $price):void{
            $this->price=$price;
        }
        function setQty(int $qty){
            $this->qty=$qty;
        }
        function __toString():string
        {
            return  "Book(name={$this->bookName}, Author(author={$this->authors}) ,price={$this->price}, qty={$this->qty})";   
        }

    }

    class TestBook{
        function __construct()
        {
            $book=new Book("First",[new Author("Abdalla","abc@gmail","m"),new Author("Ali","abc@gmail","m")],50.5,20);
            echo $book->getName();
        }
    } 
    $testbook=new TestBook();
?>