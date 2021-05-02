<h3> Dream 11 </h3>
<b>Features :</b>
<ol>
  <li>Create a team before match starts</li>
  <li>To create a team 100 points should be given</li>
  <li>6-14 players are assigned some point</li>
  <li>Enter a contest by paying some fees</li>
  <li>Contest can have varying no. of participants</li>
  <li>Update Score</li>
   <li>Leaderboard</li>
  <li>Reward Users</li>
 </ol>
 
 <b>Estimate Scale</b>
 <ol>
      <li><b>Storage </b><br/> Number of Users 100M  <br/> 100M * 1KB = 1TB </li>
      <li><b> Schema</b> <br/> Entity </li>
   <ol>
      <li>Users</li>
      <li>Match></li>
      <li>User-team</li>
      <li>Players --- id, points, skills,</li>
      <li>Match-Player</li>
      <li> Contest</li>
      <li>User-Contest -- (id, contest_id, user_id) </li>
    </ol>
  <li>
    <b>APIs</b>
    <ol>
      <li>Create team </li> - POST - users/{users_id}/matches/{matches_id}
      <li>Create Users</li>
      <li>Add Players</li>
      <li>Get Contests</li>
      <li>Enter Contest</li>
      <li>Fetch Leaderboard</li>
      <li>Update points for a particular player</li>
      <li>Rewards</li> - GET users/{users_id}/contest/{contest_id}/rewards
      <li>Update Score</li>
    </ol>
  </li>
  <li>
    <b>Latency</b>
    <ol>
      <li>
        Create team/ add players/ remove players
      </li><ol>
      <li>-- Consistent</li>
      <li>-- Low latency</li>
      <li>-- Massive Spikes</li>
      </ol>
      <li>
        Contest - Leaderboard
      </li><ol>
      <li>-- AP</li>
      <li>-- read heavy</li>
      <li>-- low latency</li>
      <li>-- spiky traffic</li>
      <li>-- may have to return errors</li>
      </ol>
      <li> Rewards
      </li><ol>
      <li>-- async (as it needs to be updated at the end)</li>
      <li>-- CP</li>
      </ol>
      </li>
    </ol>
  <li><b> Sharding candidates</b>
    <ol>
      <li>Users_ID</li> <ol><li> Calculating leaderboard will be difficult </li></ol>
      <li>Contest_ID</li> <ol><li>Fetching overall wins will be difficult after match ends</li></ol>
      <li>Tournament_ID</li> <ol><li></li></ol>
      <li><b>Match_ID</b></li><ol><li>Leaderboard query will be on match level</li><li>It can reside in a DB</li></ol>
    </ol>
  </li>
  <li>
  <b>Cache</b>
  <ol>
    <li> App Cache </li>
    <li> Global Cache </li>
    <li> LB Cache </li>
    <li> Client Cache </li>    
  </ol>
  </li>
    </ol>
</ol>
