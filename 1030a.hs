main = do
  nPeople <- (fmap read getLine) :: IO Integer
  responses <- (map read . words) `fmap` getLine :: IO[Integer]
  let sumResponses = foldl (+) 0 responses
  putStrLn $ response sumResponses



response sumResponses
  | sumResponses /= 0 = "hard"
  | otherwise = "easy"


