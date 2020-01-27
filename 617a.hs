main = do
  x <- read `fmap` getLine :: IO Integer
  putStrLn $ show $ solve x

solve :: Integer -> Integer
solve x 
  | x `mod` 5 /= 0  = x `div` 5 + 1
  | otherwise = x `div` 5


