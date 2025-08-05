import requests
from datetime import datetime, timedelta

API_BASE = "https://irctc1.p.rapidapi.com"
API_KEY = "4f240238bamsh7afacbb27aca44ap1b3da7jsnb4ffd31ecf6f"

CLASS = "1A"

# Hardcoded train info
TRAINS = [
    {"train_no": "22534", "from": "YPR", "to": "GKP"},
    {"train_no": "12588", "from": "YPR", "to": "GKP"},
    {"train_no": "12596", "from": "SMVT", "to": "GKP"},
]

headers = {"X-RapidAPI-Key": API_KEY, "X-RapidAPI-Host": "irctc1.p.rapidapi.com"}


def check_seat_availability(train_no, src, dst, journey_date):
    """Check seat availability for a given train"""
    url = f"{API_BASE}/api/v2/checkSeatAvailability"
    params = {
        "classType": CLASS,
        "fromStationCode": src,
        "quota": "GN",
        "toStationCode": dst,
        "trainNo": train_no,
        "date": journey_date,  # format DD-MM-YYYY
    }
    resp = requests.get(url, headers=headers, params=params)
    data = resp.json()
    return data


def check_schedule_next_two_weeks():
    today = datetime.today()
    results = []
    for days in range(1, 30):  # next 4 weeks
        journey_date = (today + timedelta(days=days)).strftime("%d-%m-%Y")
        for train in TRAINS:
            train_no = train["train_no"]
            src = train["from"]
            dst = train["to"]

            print(f"[INFO] Checking Train {train_no} {src}->{dst} on {journey_date}")
            availability_resp = check_seat_availability(
                train_no, src, dst, journey_date
            )
            availability_data = availability_resp.get("data", [])

            if not availability_data:
                print(f"[WARN] No availability data for {train_no} on {journey_date}")

            for avail in availability_data:
                status = avail.get("current_status", "").upper()
                print(f"[DEBUG] Status for {train_no} on {journey_date}: {status}")
                if status in ["AVAILABLE", "CNF", "AVAILABLE 0"]:
                    results.append(
                        {
                            "date": journey_date,
                            "from": src,
                            "to": dst,
                            "train_number": train_no,
                            "status": status,
                        }
                    )
    return results


if __name__ == "__main__":
    confirmed_trains = check_schedule_next_two_weeks()
    print(f"[INFO] Found {len(confirmed_trains)} confirmed trains")
    for t in confirmed_trains:
        print(t)
