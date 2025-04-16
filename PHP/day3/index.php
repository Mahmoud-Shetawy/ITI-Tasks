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
    class TestAuthor{

        public function __construct()
        {
            $a = new Author("abdalla","abc@gmail.com","m");
            echo "Name: ".$a->getName();
            echo "<br>";
            echo "Email: ".$a->getEmail();
            echo "<br>";
            echo "Gender: ".$a->getGender();
        }
    }
    $test=new TestAuthor();
?>