# Write your MySQL query statement below
SELECT a.id from weather a where a.temperature > (select b.temperature from weather b where b.recordDate = a.recordDate - INTERVAL 1 DAY )