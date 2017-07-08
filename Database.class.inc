<?php
	
	require_once "config.php";
	
	/**
	 * Class Database
	 */
	class Database {
		
		private $connection;
		private static $_instance;
		
		public function __construct(){
			try{
				$this->connection = new PDO("mysql:host=".Host.";dbname=".DB, User, Pass);
				/**
				 * TODO:Remove in production
				 */
				$this->connection->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			}catch (PDOException $e){
				trigger_error("ERROR: ".$e->getMessage(), E_USER_ERROR);
				die();
			}
		}
		
		public static function getInstance(){
			if(!self::$_instance)
				self::$_instance = new self();
			
			return self::$_instance;
		}
		
		// prevent class from being cloned
		private function __clone(){}
		
		public function __destruct(){
			$this->connection = null;
		}
		
		/**
		 * TODO: query the database and return data
		 * @param $query
		 * @param string $process
		 * @param array $params
		 * @param bool $return
		 * @return array|bool|mixed
		 */
		public function query($query, $process='', $params=[], $return=true){

			// prepare statement
			$query = $this->connection->prepare($query);

			// check if there are parameter to bind then bind
			if(count($params) != 0)
				$status = $query->execute($params);
			else
				$status = $query->execute();

			if($return){
				// fetch data
				if($process == 'all')
					return $query->fetchAll(PDO::FETCH_ASSOC);
				else
					return  $query->fetch(PDO::FETCH_ASSOC);
			}

			return $status;
		}
		
	}