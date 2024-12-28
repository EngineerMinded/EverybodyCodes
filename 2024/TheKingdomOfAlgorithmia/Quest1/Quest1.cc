/* Wayne Mack
   Everybody Codes
   2024 Quest 1
*/

#include <iostream>
#include <string>
using namespace std;

#define EXAMPLE1 "ABBAC"
#define PART_ONE  "ABCABBBCCAACAABAABCACBBCBBCBBBBABCACAACCCCACACAABABACCBABACACACABBCBCACBCBCBCCACBACCBBCABACAACCBBACCAACAAACABAAACABBCBCCABCABCCAACBBCCAAAABBBBCBABACCCCCCCACACCABCAAAAAACACBBAABCABBBBAAAABCCABABBAACCBCCBABACACACABACACBCBCCCCAAABCCCCBCBBAABCCACCBAACCCBABAABAACBABACBCACBBCAACCCCBCBBAAABBCABABCBCAACCAACCABBAAABCBAACBACCAABBBACCABBCBBCABBACBBBCBBBBBAACCCCABBBBCABCABCCCCBBBAAABBBCBACACABACCABBABCBCAAACBCBBBBCABCCAAACCCCBABABCBABABBABBAABBABAABBAACBCBCABABCBACACACACCBCCABBBBAAABABBBBBABACCABACCBCBABACBBAAABCBBAAACABCABBBBCCABCACACCCABCAABBABCBAABCAAACCBCBABBBACACCABACAACCAACCCCBCBACCACAACCCACCBBBABBCABAABAAACBAACAABACCBABCCACACBAAAAABAACBACBABBAABABAAACBCBCBBBABBBBCBCCABCACCACBCBABCCBAACCAABAABCACBABACBACABCCCCBCBBABABABBBABCACCCCBCABBAABBCACABBCACCABBCCCCAACBBAABCBCBACABACCCBABAAABBBBCACAABCBCCCAAABBCACACBCBCBCCBCACCBAACBABBCAABAABBCBCABCBBACAACCCBCBABBACCACAAAACACABCCABBCBBBBBCACCCAACABACCCCACCBBACBCBCCACAABBBCCCABBBBBCBBCBAAABCBACABACABCAAACACCBCCCBBCAAAACABBCCBACCBCCBBBAACAACBACBCBABAACCC"
#define EXAMPLE2   "AxBCDDCAxD"
#define PART_TWO "DDCxCBxCACBABxAAADADCCCBxDADBADDBDDxDCBDxCBAADxDBBDCxBBBBDCBCABDADCACDDCAADBxxAxBCCCBBDDCDABDAAACBxBCxxDBxADBCxDCABBAxCABCDDxxCCAxDCDAACAAxBCAxCCDBCxCxBCxDAxDxxDxBADACCDAAACCCBDAAADxDDDDxBxBCBDACDDCBABCBADBABDDBABABCCDAxAAADDDCBCBBCBCxxDAACBADBxCCBDCDxBxDCACCCCCCCAABDCCxACDDCAAxAADACBBACADCDADDBBDBBBBCAADCDxBBADABCBABCBBBBCABBBCBAxCxxDACDDDDCDxDCCDAxCCDDCxxCBBAACABDABCxADADBDBBDCxADDBABDCCCxADAABCDDDBBDADxABBACAxCBBACDDDBCxDBCCBDBDDDCCxDDDBBAxDBDDACABABBxxDACBBBxDxDxADABBDBBAABBADAABDDCABBBDACBACACDDCBxDxADCAADDAxBCCAAxBCADDBxCBADxDCxxxCxDxDAADDDBBABBCxADADDADxCAxDCAAACxABABBAABAAxxBxADBAACABABCDBBBxDDCCCxDAADCDCDBxADBABCDxDADxBDADBBBCCBCBABCACBDBAAACxCBDAxAxCDADBAADBCDAxBCAACBBBABADBCDAxCABACxCCCCxCCBBDCDxxDADxCCCBxDCAADDBxCAACDCCCxDCCDCBCBDDADBADBxAADDBxxABACBBBDxCAADABCxDxACDxBCDCCADDxCCACBAxxCBDxBCCABADACCCCDBCDAACAxCCCDACDxBADBADBCACDDAxBBBDxADCxDDDCBADCCAAAAxCCABCAxCACBADBADCABCAABADBBBDCDAxDBDCDADBDAADDCxDBAACCDCBxBACBBxAxBADxCADDBDDCCADDDDCCAACxBxDDDBCCBCCDDCCDDBCCADxABDBCDBAxAAxAxBCDBDxAxADBxCDDBDBxCAADCBAxDDACDDDCABCCCDBDxCBDDAABDCCDCDCCACCCBBBBBxDBxDDBCDADDAxADBCCDDxAADCCADxCBADDADCADADBAxCDABCCDDCDCCBCCDAxDBBBDACCDCCCDxAxACDxCCAADDCxCACDDDDxxAxBCCACCDACDBBAABCDDDABBBACCBAABBCDBDBABCBABCADxBADACCDCCBABxCDDBxxBAxCDxBABCABDxxACDxBxAxCxDAxACDBACBDDDDDBBCCxCxABAxADxAxBDABxBDDxDACDxCADCCACxDCADCDCCCBDBCCDxCBBCBDBACABABCCBDxADDBCADCxCxDBDDAABBDABABCAxDCCDBABACCCDDCACACAABBxACBDBACxxBADCACBDBBABDCDCADCBADxDAAxACBxADAADCBDABCDxxDAxAxACCDCCBDBxDDDDABADCDBBAADABCBDCxAAxDAxBDDBCDBCBAADBBCBCxDDDADCDADABxDBBBDBAxAxAABCADBBCBDCBCDCBBCBAACADBCBCBDCCBCACADBCBDBCxCxBDxCCCAAAAADCDDBBABCABxAxxCDBDDABDxDDBxDDxxABBCCDDDDBACxCDDABBBCCDBDxCADDDCDABxCxACACDCACDDDADBDAADAABDCBCADCDDDCCCDAABDDCABCBDDAABDBCDADAADABAxABDBDBAACACxBCCxCCABDBxxCCDDDCBBCxCBCDDDABBBBCxDDAACABDCCCCDACBACBDxADADCDBBxDBABACDDDABCCxABCDDDBxxBAADCABDCCCBxCCCCDBCBxCCBCxCBABABBxCCDABDDDBBBDCCADCAxxCBABCAxCDBDBCCBxBCDxBBAACxCCBBDCDDxABAxBADBBDAACAADDBDAAxCDADBDCCBDDDACBADACxBDABCxCAACCADCBAxAxADDDCCCACADBADBBCCC"
#define EXAMPLE3 "xBxAAABCDxCC"
#define PART_THREE "xDDCDCxxBCBCAxDxADDBCCxCBDBDBBxDDBBxxxDxDxAACDCBxBDBBxBBxDCACCCBBDDDCCABCCCBCABABBCCACBCDAxBABCDDABCDBCDCABCCxDABBBACDCDBxCBxAABCxBxBAACCABDBCDBBBDCCDDBAABAxCBxxxADADCABBABBCACBAxBDxDBBBCABBxBBxADDAAAABACDAAACxAAABBxACADxBACxCCCCCBAxxBxBACxxxDBBADDCxBDCDBDBBxDDDxDACBBBBACCDABDAABxBBABDDCBABDBDDDDCCCxACDBxxDBxDBAAxDDCBDxCCxCAxCABBCABCCxBxxDBCABDAAABCCADDBDBDxABCxBDDxBxBACDACCDDxxBBDAAADBADBABxBCBxDBCABCxBABBDxBxxCDBxCxCCADAABxAxAADCDCADACABCxCxBxxABBxCxxxxACxABDxCDAACxxDCxxxCDDBCDxDABCDDxBBCCDxBCAABDDCxDCCxBxBCBADBCABBCDCBDCDCDACxDDxDCCCxCBAACDxBAACCDAABCDAAxxDBCBBADCCxCADBAADCxCDBBDDxBxCDAxACBACCxBBxBCDCDBBCCCBDBCCDxACCCBxABBDBAxxCACxABBBBDBxAxDDBDACDBxBCADCxDBDCBxAACACCCDxABBBBCxBCBAxDCADBxDCCCDACxCACABDBCACDACCCAxCDDxADxAxxADCBxCACABBDBCCBxBDDAAxDAxCCADxxDxDAABCDDBABACAxDACBBDCAADBACxBDAxADCCCAxxBBxACxAxCDCDAxDxCCxxxBDDAxBBACAxCAABDxCABBABBDBCBABDBCDxxBDxxAxBxCABABCxBCDADxDAxABAAAxDxACCBBDBxxBDDABDABxBxDAAxCDBDxCCAADCAADBBBCCBBxBxBxBBDDxDAAAxxxAAAAABDCBDDCAxxCCCBDDBCADCADCCxBBCCCBDBADCAADBxDBxxDBDDBCxBxCBCxABDDABCCBCACDxBAABBAxBCxCBACCxCACxBDxDBxBAxBDADAAxBxABxBDCCDAxBDxCCxADDBBxCABBBDBBCDDDxBBBxBDCAADxxBDDABxCCBBAxBBAxxxBDBCABxBDBxDxxCDCDxxxDABADDCCCxBDCxDBxCBxBxBAxBxCxBCDDAAxCxxDAxCACxBACAADADxxBCxDBDDCAxBDDDCCxxABCDDCBDCxAAxDABBxBDBBAACxxBCADDxCCBxxDADBBxCxCCxDCxCAADCBAxCxCACDCxDABADxBABBxCCABxADAAxBDDxDAADDxCCxBDDDxABxxBxABDBxCBABCBBAACBCCCCDBxCCDAxxDCACDDDDBCDCAACCDBACCDCBDACBDCCDDAxBBDADxxDBxCCABCAxDxBxxDADCAAxDxACCDCDCACCBBCxCxCADxABAxBxBCBxBBBBxCDxxBxBACxDDCAABBCxBDCBxABDCCxAAxAxDCxAxBBDBDxADxBACAADBxAABxBxDCBAxAxBxADDxBBxxBDBxBBDCxADCCBDxDCCDBDDDADCxACCBDAxxDCBDCADDDAAACCABCAxBDADBCDDxDADDBBADCDBCCCCBCBxxCDABABxCCBDBDxCCxDAAACxxxxBCxDADABxABBDBDBxxxAxCxADDBCDBDCADxAABxADABCDAACDADAxDBxBCCBACBCADxBAAABBCCxDBxDAxDACBABAxxDDDDADBxxxCCAxADxACBCxCACDxCAAxBAxxxBDCACxDBxCAxxADCADCAACBCDxCxAxDBCAACCADADCDDACxABxDCBDDBAxABxBBCCAADCxDACBABDBxxAxDDCABBAACAxAxABxABADxCxxxABACDBBBDCBDBxDCCABxBxDxBBCxCADCBDxDACBDxDABxCDxADxDABDAxCBxBADAxDxADCDBxxBxAxBDDBDDxDCBDAAADxBCxAxDCxDBxCAxBDDACDABBDxxCBCCADCBAAABDDBxADAxxABAxxAxBxDxBCDxCBCCCACACxBxBDAAAACxxCCCDDCDCDxBACADBxDCCxDBABDCBAxBxBDACxBABADCxADxAxxxBDCDDBBCxBBxDAxCBCCCDBAABAAAABCBBBxABDBBDCCAxABADCBxxxDCAAxDxxCDBBCxABBAADCCCDDAACADBBAAABCCxACBxDBCCCxCBxDCBAAxABADxDBBBCDAxxxCDACDDCBxxAAxxABxDABDCxDCxDxxxBDDxxCACDxxDxBDAxABABDAAABABxxDxxBBBAAxxABCxCACxxxxCDACxxxDBABBCCCDxDxxxAxBDBBxBBACBxDDDDBCCBDBBACxBBCxxACxBAAABxDDxBxxBBACCCxBxDDABADABBCDDxADDCDDABDDxDDxxBCBBAAAABDDBDxDAxCCCDxxxBDCCCCADADDxCxDxDxxxBAxDxDCDDCBCBxCCxCACDDBDDxxCDxBDxDDCBDxxxBCBxADDxCxBxABBCBxDBBDDBABxCBAxDAAAxABADCBBDDAxDBBxDBCxADABCxCxBDxACBCAAAxBxDBBCBABDxBDDACDBBxDDDxCDABADDxxBDxxCxADBDAACCCxABAACxxCBCDACCDDACBxDDACBDBDABAABBxCDxBBDxDCAADAxCxABCxACDDDxADBxAAxCBBBCDxBBAABABxCCBxDxBCCxBBDAxDCAxCxAADCDCDCDCBxCAxDxDxBxxxDBAxACCDAACxBxxBABAxxDxxDACCCAxDACCACDADxDABxDDDDBDBBxDBCABDxCBAxxBCDBBxxDDADBCAAAxDBAADAAAxDxDDCxxCxxADDxDDCCxxxAADBCDDBxACACBABBxADDCADADAxxCDxDCxCAAxACDxABBxAAxxCxxBBxAADCBxxDxBAxCDxCDBBCCBxDBxDCCCBACBDAADCDCDAADCBBCABDDxBxABDBADCCDBDCCCBBxBxAxCxCDBxDBCABxxBAxxBxDBADxCBxAxxxxBDDDxxBADCDDCBxxDxDxCBBCAxDAxDDCAxDxBxDCxAAxAADDxCBxCABCBAAxBxCBAACAxDBCBxCBxCACxxBDAABCBxBBCCDxBABCABAxABCxDACDADBAxCAACDxAxBBABDDBBCBDCABACBDBDxCxCDxxCCDAxCBDDxDACAAAxxABxBDxBDCACAAABCDCxDACDAAxDBxCxACBDDDAxBABCAxxDACxDxACBDBAxDDDAxBDABDAxDxBAxAxDDxDBCDBAxBCCABxCBACCDCABCxAAxDBxCBBCCDxDAxxDDAxCCCDCxBxDxCCAADBCBABBxACxCxxxDAABDDCDDCxBABDxCxxDDxxxxxxCADBBCxAxAxDxCBAAACDxAxACDADDBBDxBCADAxxDxCxADACxDxBxAxAAxxBAABABDDxBDDCDACBBABCDBCDADBxBBDCAABxDBBCDCxDBxxDBxBAxAxDBBDAxCACCxxAADDCDBxACABCxDDBDDDAxCBDDBxCCCxDxDBCxCxACACCAACCACAxxCDACxACCxADBABBDBDxDxBxxCBxBDDDBACBxBxAxABAxxxxBxBDCxBxCDBDBxBDCDDADxDACCCDBDCAADADDCAADxxCBACBDBxBCDDCCACAAADDBACBBBDBAAACCAAxDBxBDBCADCxAxxBAxxBCCBDAABADABxDxCBBxBBBADCCDBAACADxADxDxACDBDCDACxBDABCxCxADBxxDCDCCDDCBDBACBACAABCACxAAABDBCBCCBxxxCBxBBxABBxCBDAxDCxBCxxDACxAACBBAAxADxACCDBDCDCxAxxCAxCAxDDADCxxADBxBABxCBDCBBCADxxBBCBBDCBBCDCBADAxxDxDDxxABxxADxAxBAABDxCxCCCDxDDDxAxABCADCAxxxABDCDAxDCDABDDDDBDADADBxBBBDxBDBBCAxDxDBBCBxABBADBABxBxCxDCDAxDxBCAxCBABBCDDDxxCDDADAxxCDCxBCCDDADCxxDACCxADCAADxADADAxAxBADDCBxABADxDDCDDDCAACACDBxACCADADDDDABDDADxCxBBDxBxxACADBBCDAAxCCDDDCBCDBBxxxCxCDBDCxxCCxDCBAAxCCCDAxDxxDDxCDDxxxCxACDCxADCxBDDxAADAADDxACAABABDDBCDAAxAACCBDAABDCAABCDxACDBBAxxBADBBADCDBDCxDxDBADCBxxBABAAAABCCCCxAxCCAAxBxBDBxBxxABCBCxxCCBACCDACCACABxABxDxxBCBCCDCxABxADCAAxxDAAAACDDxDDDABDADBDCCAxABADCxADBBAAAADDBCBCDACCBCDBCCxBxCxBxDBDCxACxBDCxCDACAxxDCxBBDDCCCxAADACADDADDBCxAxCxCBCxCCAxBCCDDDACAAxCACDxBxxxBxBDACDxDADBCAxBCxAADCDBADBBBxBBxADAxCBDCBDDADDBCCABxBAxBBxBCCACBCBxACBxCAAxDDBBxAACACAxCCAACxBBABxBCxAAxxCxxADAACCCxDBxxDBACxxAADBBACDAxxDBDxDBAxxABBCDBxCABBxBDDCxxACBBBDBDxCBxCADDDAABADxDACBxBDBCDBDAxBBACCxDCADxABAABABCAABBxxAxCBDCxCCxxBBxACCAABCCBBCAADDACADDACAxDADABxDDxBCCABADBBABDCBxCCACxADBDxBBDCBxCCxxBCDDDAADCBCCCxxxDxCCDCDCACAxxCBCDxDDxDADCDADCCCDxDBBBxAADxDCxACBDBCABDADBBxABDxBACADACBAAAADADBDDBBABxDxAACDxCBCBxCCBxxDxCACCxAAACACCCAAxDxBCxBDxBBDABDABCDxDxCCAABBCBAAxCBDCBCADDAAACCCAxDAxxABxxADDDxCBxBCDBxADxBxBDBAxBDBDxBAAxCDBDxAxBDDAAAxBBADDBABDBCxxADADxDDCBCACBABxDDxDACAADCBADxBxxxBDABBCDCDDxBAADDCxxBDAAxDxACCCCCBDDBBAADCDBACDxxCBABBBCBxxCDDxxBxDxBAABAABDAADDCCxADACxBDADAxDxCAxxxCCxDxAxAxAADBADDDxDBDACAxBDABDACxDxCxxACCACxDCxADxxAxDABABBBAxBxBxCBBBCBADDxDBCDxBBAxDDxDAAxABAADCBBxxAxBCxAxCBxCDADCCBADBBAABCACxDDAxCAACBCCBCCACDCCBCADxAxxAxxDxADxDBCADxAAxxAAxCBDxxDABAxAAAxCCxxBCACBDDDxAxCxBBCACBABDBDDBDCCBCCACxABCBAxCxCACCBCCDAxxCBBBADCBBACABDAAAxDDxAxxCAxCCCCDBxACAAxBAxADDDAADAxBxCBDDADCxBBxBCBDADCAABAxxADxCBBxxCCBBCBBDBCCDxBBBDDDDAxBBDCxAABBBxxBxxDBAxDBDBxxCxDDBADxxAAAxDADCxBDBxBxBCBBBBxCDBxxBDCBBAxDDDxDxBDBBCCDxBCDACBABxCABBDDBDABCDADDDxxCxBADxAxDxDxACxDABAAACDxxCDACDDAAAACCABDAxDADBxAxBDxDDxCDxCxBACCCBxACCCADDxADBxBBxxBBDxCCCxBDDADxDCDACDDCxABAxxBxABCACBBxxDxxDCBAxxBADADDDxAxABBBCABxDADCAxABxCACDCACBDDABDxDACBADDDCDxxCDABxDBDBBxDACBCCDxDBBDxAADDxBAxDDCDBxDCBBACxBCCxCDBDxCxAADDxDDBCDxxxBCxADCCDDBxxBBAxxCxBAAAAAACCxBACDCAAACDADAxBADBDBBDABxxCCAxADxBDxDxAxBCBDDDDCAAADDDxDxAxxDCBDCDxBADDCCCDAxBCxCCAxDBAAxCxCBxCBDxDxBBDBDxCAACDDCDxCBBCCxCxDBCACCCxDDDDDAADAxADCxAAxCDACBBDxBDDDDAxDxDBCCxAxCxDBADxxAAABBBxBBCxCCxACBACxBAABAAADxAACxCDAAAAADCBACACAADDAxBCAxBxDxxAxxCxxABADCDCxDxCBxCADBBxABBxBDxBCCDBxAADDBDACxxDCAACDBxBAxAAAAAxxDADAxDxCCBDxCDACADADBxDBDBBDxCxxCDxDABCDDDxxDCABxDxCBCBCABBCAADxDBBxCxDCCxCxCDCCBBDxDBCCBCBAxDCBxABBBDCAAxBxBBxBBxCCDBxDACABDADAxDxAxxCDxDxDACxAABBxxxBCBxDDDCCxAxDADCxCADCxDBDBCCCBDBCABCxCCDACBADDxBCCBBCBxxBABCADAADCBBBAAxBCBBCCBAxDxxxDBDAxxCBDxDCBACADxABxCxCxDDBAAADBABDDBxCxBxBxABCBBxBDACBCCAxDDxDBDxxxCBAACDBDxCCBBCxADxxCBBxBADBBxACxBABxxDAAACBBDDADBxAxxxDCCCAxDBAxBABCAAxDDxxCDAxBADxDxBBCCxxAxBCAADDBCxxBCADBDDADxDABDCDCDABABDxABDAABCDxDxDAxCCDCACBxBxxADACAAAxADCCxDDxDCBxxxDCCBACDCxBDxDDBADxBCBCAxABCDAAxxxADCCBBDxxDABCDDxBCAADAACABxDBxBBDxAACDBCDCxCDCCDCxDDBxCCBCCAxDCxBxABAxxBBACDBxBxBAABAxDBDDCxDDABACBCABDxCDDCCBxCDCCBBCABxCBBxCxACxAxDDBCCAxDCAxxABCCDACCADABDBCCDDCxAxBBBxxACBxBACCDDAAAAADACCDBAxDBxDCBABACxCABBBCCBCBADACCxACxxxBxAxDxADCCBCDxxxCAABCCxBDACDCBAAxBCBCBCDxABDDBAxDBAxAABDBCBCCCCDxDABAAABDBDBBxxBDBCBAxABBDBADABDxDxBCCBCCCxADDBxxxACBxxxAxBxBBxxDCDxCCxxBxBBBCADBxCxxBCCxBBxADCCBxBADCCCDDAxDADDxDCACxCxCxAxDCCBxxDCxxxAxBBDBxBBBABxCCABBxDBxCxxDBAACBxCxDxBCxBABABDxAACDDBDCxAACDBCBxxBDCBDDxDCBBCDDxDCDxCACBxCDAACxxCDBDACCDAACCCCxAADBxDACBDDCDADDCDAAxBxDBAACBxBxxDBCCDxBxABDDxDCxAxBDAACAxDxxCCCDADDADABAxADCCCDBABCDBBADACBxADCAADBABxxDxACCCxAxxDBDBDCAxABxAxADBxDBDBACDCDCCAAACACCACAABCCAADDCxxxDCDxDBCCBABDBCADxxDxDDCBCBBCxCACCxCDBDAAxDxBAABxxDCABCBBAxAxCCCDCACCDCxxADBACADxCxBBBDxADCBBBABDCACCBCCxxxxBxBxxBBAAADCCBBDxAxADACxxDDxBxDBDxBxAABAxAxCDABxxDCxCCBCDxDBABBBACxBxBBCxDACCDxBBCAxDDCCDADAxCDBDDBCxAAxCCADxDxCDBCBABxADCCDDADxBBAxDCxABxxABCxCxAAACxBDBxxxDBBBBACCBCxAAxCBCACxDADBBADxCBxxDxAxCCBCBxBAxCDABBCCBCDxACxCCABxxCADCCDxDDxBBAxDBDBBBCCDDDBBBxBDAxBDACADCxxxBBDCDBxDCCxBxxABCBxxDBxBBBxBxCDBDBxCCADBBxDCADDBDAxAABCDABDABCAxCxBBCAABxDDACAAxxADBABCBxBxADDADBCDAAxCCxxDBABxAxABBAxCACDxBBBCCDDDABCxDCCDACxCDDxCAAABDxBCAABACDCDxACxBCBxCDxxxDxxBAxCDACBxACABDxBCDxDDxCCAADxxBCCDxCBxDDxCDADBAxxDABDCBDxxxAABxBCxDxxBCxCDDCBBDBAABABABBxBDABxDAADCxxDxADxxDCCBAAAxAABDCCBACBDxDAxBCDBxAACDACABBCCACxABxBCDDDAxBDBCBDADACBxDBDBDxABxDCBxxBDABxBBCBBDCBBCABAxCCAACBDCDCAACABAxBDDCDxBACABDAxBxBDxCxCxCxDCBCBBDBDCDCAxAxDDxDBDBBxDxCACCAACBCCDBCADxCAAACBxCBxBABACBBDAADxBxCxCCBxDADxACCDBxCxDBADCCABCCCDCDBxBCCBBBCDCAACxCAxACxADCxBBCDCBADxBACDCxBAxBBxBDACxCCCBABADABCCBCACACBACDxADAABCDCCCCCDADxxCxABDCxxAxBCxABABxBBBBDADABxCCCDABDCBCABDBACCxxAxBBDxDDCAxCxBDCACCxCxDAAABAxDBxDACAADDCDxCDBBxBACBAABADACBACAADAxxxAADDAAxCCCxxCCxCABxABCxxADCBDADADxCxAACACDDDBACDBDBBAxCDCxxCDDCAxCAADxAAxCAxACCDDADBBBxABABBxCCxCDDCBxxDxCADxAxCCBDCxACBAxAAABxCAACBCABDxACCBACBDxxCCCAxBBDBDBCBxCBBDDDDABCCDxCxABBAABDCACxCxCCBxBAADxDBBAACxBCxDDDDDAxxxDCxCDADBDAxBCCxDCxCxBBCAACBAxDAxDABBDACCBCBABDDCAAxCCCAACCDxCDCDxADBxCDDBxCBxABDADAxxABCBDABBDDAxBCBxDCBCBACBCCADxxDxCBxxDBABCDBDxADCCBCCBBBDDACDAxBBBDBCADADDCBxDABCBCCxBxCxDDBABCxAxxxDCABDCDCCAxxCCDAxACDCBBCDx"
// Well Damn, that is long

int getValue(char);

int main() {
    // PART ONE
    int part1 = 0;
    
    for (char c : PART_ONE) {
        part1 += getValue(c);
    }

    cout << "Part One :" << part1 << endl;
    int part2 = 0;

    // PART TWO
    string partTwo = PART_TWO;
    for (int x = 0; x < partTwo.size(); x = x + 2) {
        char c1 = partTwo[x], c2 = partTwo[x + 1];
        int addOn = (c1 != 'x' && c2 != 'x') ? 2 : 0;
        part2 += getValue(c1) + getValue(c2) + addOn;
    }
    cout << "Part Two :" << part2 << endl;

    // PART THREE

    int partThree = 0;
    string part3 = PART_THREE;
    for (int x = 0; x < part3.size(); x = x + 3) {
        char c1 = part3[x], c2 = part3[x + 1], c3 = part3[x + 2];
        int multiplier = (c1 != 'x') + (c2 != 'x') + (c3 != 'x');
        multiplier = (multiplier == 3) ? 6 : (multiplier == 2) ? 2 : 0;
        partThree += getValue(c1) + getValue(c2) + getValue(c3) + multiplier;

    }    

    cout << "Part Three :" << partThree << endl;    
    return 0;
}

int getValue (char c) {   // Part 1 and apparently 2
    return c == 'D' ? 5 : c == 'B' ? 1 : c == 'C' ? 3 : 0;
}


