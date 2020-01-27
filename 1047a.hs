main = do
  n <- read `fmap` getLine :: IO Integer
  putStrLn $ foldl (++) "" $ map ((++ " ") . show) $ solve n


solve :: Integer -> [Integer]
solve n
  | (n - 2) `mod` 3 /= 0 = [n-2, 1, 1]
  | otherwise = [n-3, 1, 2]