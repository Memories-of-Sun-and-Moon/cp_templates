# AHC用テストケース実行ツール

## 各コンテスト毎に必要な変更の手引き

### 1. test_all.py

- 9 行目 ``AHCXXX`` を変更
- 10 行目 ``AHCXXX`` を変更

### 2. archive.py

- 17 行目 ``AHCXXX`` を変更

### 3. concurrent_executor.py

- 13 行目 要求されるタイプを確認

### 4. score_calclator.py

- 12 行目 要求されるタイプを確認

## 注意するべきこと

### ``out`` という名前のファイルを作らない

一時的に作成される ``out`` ディレクトリと競合するため