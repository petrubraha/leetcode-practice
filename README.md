# LeetCode-Practice

My LeetCode solutions, synced automatically from LeetCode to this repository.

## Goal

Work through the [NeetCode 150](https://neetcode.io/practice/practice/neetcode150) roadmap:

- **One new problem per day**, following the NeetCode 150 order.
- **Plus the reviews LeetSRS says are due that day**, so older problems stay fresh through spaced repetition.

## Tools

These are included as git submodules at the top level of this repository:

- [LeetSRS](https://github.com/mattcdrake/LeetSRS): browser extension for spaced repetition on LeetCode. I rate how well I remembered each problem, and it schedules the next review. It also tracks progress on the NeetCode 150 roadmap.
- [LeetSync](https://github.com/LeetSync/LeetSync): browser extension that pushes every accepted LeetCode submission to this repository (one folder per problem, with its `README.md`).
- [neetcode-submissions](https://github.com/petrubraha/neetcode-submissions): my NeetCode solutions, pushed automatically by NeetCode's GitHub Sync.

## Daily workflow

1. **Solve the new problem.** Pick the next unsolved problem from NeetCode 150.
2. **Check the extension.** Open LeetSRS to see which problems are due for review today.
3. **Solve on LeetCode.** Submit the new problem and the due reviews on LeetCode. LeetSync commits each accepted solution here.
4. **Resubmit on NeetCode.** Submit the same solution on NeetCode so its NeetCode 150 progress tracker stays in sync. NeetCode's GitHub Sync commits it to `neetcode-submissions`.

## Infrastructure

What happens behind the workflow, from the one-time GitHub sign-ins to the commits each submission produces:

```mermaid
sequenceDiagram
    autonumber
    actor Me
    box Browser
        participant SRS as LeetSRS extension
        participant Tab as LeetCode page
        participant Sync as LeetSync extension
    end
    box LeetCode
        participant LC as leetcode.com
        participant GQL as leetcode.com/graphql
    end
    box Cloudflare
        participant Auth as auth.leetsrs.com<br/>(Cloudflare Worker)
    end
    box GitHub
        participant OAuth as github.com/login/oauth
        participant API as api.github.com
        participant Gist as Gist<br/>leetsrs-backup.json
        participant Repo as leetcode-practice
        participant NCRepo as neetcode-submissions
    end
    box NeetCode
        participant NC as neetcode.io
    end

    rect rgba(127, 127, 127, 0.12)
        Note over Me,NC: One-time setup
        Sync->>OAuth: Sign in with GitHub (scope repo)
        OAuth-->>Sync: Access token
        SRS->>OAuth: Sign in with GitHub (OAuth with PKCE, scope gist)
        OAuth-->>SRS: Authorization code
        SRS->>Auth: Exchange the code
        Auth->>OAuth: POST /login/oauth/access_token with the client secret
        OAuth-->>Auth: Access and refresh tokens
        Auth-->>SRS: Tokens (the worker does not store them)
        Me->>NC: Connect GitHub at neetcode.io/profile/github
    end

    Me->>SRS: Open the popup and check which reviews are due today
    SRS-->>Me: Due problems, read from browser.storage.local

    Me->>Tab: Write the solution and click Submit
    Tab->>LC: POST /problems/{slug}/submit/
    LC-->>Tab: submission_id
    loop until state is SUCCESS
        Tab->>LC: GET /submissions/detail/{id}/check/
        LC-->>Tab: state and status_code (10 means Accepted)
    end

    par LeetSRS
        Note over SRS,Tab: Content script wraps the page's fetch and XHR and sees status_code 10
        SRS->>Me: Rating menu on the LeetCode page
        Me->>SRS: Rate how well I remembered the problem
        SRS->>SRS: Schedule the next review and save to browser.storage.local
        SRS->>API: GET /gists/{id}
        API-->>SRS: leetsrs-backup.json
        SRS->>API: PATCH /gists/{id} with the whole document (last write wins)
        API->>Gist: Update leetsrs-backup.json
        Note over SRS,Gist: The same sync also runs on browser startup and every minute
    and LeetSync
        Note over Sync,LC: Background worker sees the POST to /submit/ through chrome.webRequest and waits 5 s
        Sync->>GQL: questionSubmissionList and submissionDetails, with my LeetCode session
        GQL-->>Sync: Code, language, runtime, memory and status
        Note over Sync: Continues only if Accepted and submitted less than a minute ago
        Sync->>API: GET, then PUT /repos/petrubraha/leetcode-practice/contents/{id}-{slug}/README.md
        API->>Repo: Commit "Added README.md file for {title}"
        Sync->>API: GET, then PUT /repos/petrubraha/leetcode-practice/contents/{id}-{slug}/{slug}.{ext}
        API->>Repo: Commit "Time ... Memory ... - LeetSync"
    end

    Me->>NC: Resubmit the same solution
    NC-->>Me: Result, and NeetCode 150 progress updated
    NC->>NCRepo: GitHub Sync commits "Add: {slug} - submission-{n}"
```

## Cloning

```sh
git clone --recurse-submodules https://github.com/petrubraha/leetcode-practice.git
# or, in an existing clone:
git submodule update --init
```
