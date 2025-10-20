<img width="1200" height="200" alt="Image" src="https://github.com/user-attachments/assets/fbb6bd1a-58d5-4d60-bcd8-943422fbbf5c" /> <br>

>UnrealEngine5를 이용한 3인칭 액션 소울라이크 게임입니다. <br>
>사이버펑크 세계관의 로봇 손오공이 던전을 탐험하고 몬스터를 처치하며 탈출을 목표로 하는 게임입니다.<br>
>전통 설화 × SF 감성의 융합으로 익숙하면서도 새로운 액션 경험을 제공합니다.<br>



---

## 🖼️ 데모 / 스크린샷

![Image](https://github.com/user-attachments/assets/f293eaae-86fe-451e-bcff-4d07438f249d)

---

## ⚙️ 개발 환경

- 개발 도구: Unreal Engine 5.6, Visual Studio 2022
- 프로그래밍 언어: C++
- 개발 기간: 2025.09 ~
- 개발 인원: 개인 프로젝트

---

## 🎮 주요 기능
- 전투 시스템
- 몬스터 상태 기반 행동 로직  
- 미니맵

---

## 📌 게임 방법
| 조작 | 동작 |
|------|------|
| **W / A / S / D** | 이동 |
| **Space** | 점프 / 2단 점프 |
| **Ctrl (왼쪽)** | 회피 (구르기) |
| **마우스 좌클릭** | 기본 공격 (콤보 5회) |
| **Q** | 스킬 사용 (2단점프 시 다른 모션) |

## 😒 개발 과정 & 어려웠던 점

### 1. 층 판단 로직
❓ 던전의 구조가 3층으로 구성되어 있어 층 별로 다른 미니맵을 보여줘야함. -> 층 판단 로직 필요 
🙄 초기 구상
- 층이 바뀌는 부분에 트리거 박스 설치
- 플레이어와 트리거 박스가 Begin Overlap 되면 미니맵 변경
- 문제점: 트리거 박스 내에서 방향을 바꿔 되돌아가면 잘못된 층으로 판단

<div align="center">
  <img width="70%" alt="Image" src="https://github.com/user-attachments/assets/82b6e327-4dd7-4045-808d-f873427f0244" />
</div>

💡 해결 방법
- 내적을 이용해 진행방향 판단.
- (트리거박스 좌표 - 플레이어 좌표) 진행 방향 벡터와 트리거 박스 방향 벡터를 내적함.
- 내적은 결과가 양수면 정방향, 음수면 역방향
- BeginOverlap과 EndOverlap 시 방향 판단 실행. 정방향이면 2층, 역 방향이면 1층처럼 변수로 층 설정

<div align="center">
  <img src="https://github.com/user-attachments/assets/b02fe0f8-99a5-446e-9de1-757807b8bf8f" width="400">
</div>

## 🚀 향후 계획
- 신규 맵 추가
- 몬스터 추가 및 보스 패턴 다양화
- 히트스탑/카메라 흔들림/시네마틱 등 피격 효과 추가
- AI를 활용한 데이터 분석

## 📄 프로젝트 문서 (Notion)
[🔗 노션 페이지](https://www.notion.so/Cyber-Wukong-26a3bd2b36e280baaa27c245d2205269)
