//
// Created by 本間優之介 on 2023/02/25.
//

#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("no_name",
				required_grade_to_sign,
				required_grade_to_exec),
		  target_("no_name") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
		: AForm(target,
				required_grade_to_sign,
				required_grade_to_exec),
		  target_(target) {

}

// AFormの引数にsrcを渡してうまくいくの面白い
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), target_(src.target_) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	this->AForm::operator=(src);
	const_cast<std::string &>(this->target_) = src.target_;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	// ここでthrowされた場合はそれ以降の処理に進まない
	AForm::isExecutable(executor);
	std::string filename = target_ + "_shrubbery";
	std::ofstream ofs;
	// iosクラスはios_baseを継承してる eofbitはファイルの最後にいったことを示すから今回はいらない
	ofs.exceptions(std::ios::badbit | std::ios::failbit);
	ofs.open(filename);
	ofs << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNHHNHMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNHY````vNMMMMMMMMMMMMMMMMMMMMMMMMMMMNMY\"?MMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMHY```````?NMMMMMMMMMMMMMMMMMMMMMMMMH@'````dMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNM^``` ` ```vNMMMMMMMMMMMMMMMMMMMMNM\" ``` ``JNMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM#M%``` `` ``` WKMMMMMd@!`7NMMMMMMM#=```` ``` WMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMdF`` `` `` ``` HMMMNB!````(NMMMNM=```` `` ``.MMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN#``` `` `` ` ``.MWHY`` ````WHMHY``` ` ` `` .HMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM#M'`` `` `` `` ```?M^`` ` ` ``(M^``` ````` ``JNMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMWF`` `` `` `` ` `` M[````````.#``` `` ` ``` .MdMMM#\"\"!!`_?ONMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMM# ``` `` `` ```` ``,N.` ```.JD `  `` ``  `` dNH9^`````````.MMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMdt` `` ``` `` ` `` ``WL`` `.d$````` `` `````.@```` `` `` ``(NMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMN#``` `` `` ``` `` ```,M.``.M^``` `` ``` ` `.M>``` `` ` ``  dNMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMH%` `` `` `` `` `` ` ``dL`.@```  ` `` ` ````.@``` `` ``` ` (MMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMM#``` `` `` `` `` `` ```,NJD``` ```` `` `` `.H:` `` `` ```.dBMMNHHHY\"=~(HM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMWF```` `` `` `` `` ``` ` MF``````` `` ``` ``.M`````` ...JkMY\"\"! ```````(MM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMH\\`` `` `` `` `` `` `````` .dMWM_`` `` ` ```(N...JkHY\"^````````` `` ``.MMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMM#^`` `` `` `` `` ``` ` `.g.dBMWNH\\`` `` `` `` _~~`````````` `` `` ```.JMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMHHH#``` `` `` `` `` `` `````d]JF T\"MF`` `` ``` .JgNa,`` `` ` ` `` ` ``  (MNMMMM" << std::endl
		   << "MMMMMMMMMMF??YNHMMHY^,MY!```` `` ``` `` `` ` ` `.M(M! .dY````````.JMNa, .M `` `` ``` `````` gNMMMMMM" << std::endl
		   << "MMMMMMMM#H!````(UH~  .M<`` ``` `` ` ```` ```` ``.D.TYY\"~`` `  ``.M=MhgF.dF``` `` `` ` ` ```JNMMMMMMM" << std::endl
		   << "MMMMMMMM#M `` ```?h   Jb```````......`` `` ```` ``````(MMa-.```.M' .?_.#^` ` `` `` `````  -MMMMMMMMM" << std::endl
		   << "MMMMMMMMN#``` ```.H|   M;`..&HY\"\"???M,`` `` `````  ``.HL..-Mt``,N ..d@!u%`` `` `` `` ` `.dNMMMMMMMMM" << std::endl
		   << "MMMMMMMMM#`` `` ``vMh. (YY\"^        ?N.````..d#M|````,M=udB!``` 7\"9u.dY^````` `` `` ```.MMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMW@``````````Jb               4L`.J#\"`  db```` ?\"\"```` ```?\"!`````  `` ``` ``` JMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMHb` ` ` `` `.N                \"\"\"!     .WagHWY\"4@```..` ``````` ``` `` `` ` `.MdMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMHF``` `` ```,#                                 ,MWMY\"M[` ` ``` ````` `` `` ``(NMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMHF`` ```` ``(F       .g,                             W]````` .....``` `` ```.MMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMHb``` `` ``.H\\     .gMMMb                            ?\"\"\"\"\"\"\"\"\"\"\"W]`` `` .(gdMHMMMHHMMMMMMMM" << std::endl
		   << "MMMMMMMMHN ```````.dY    .MHZZZXN                                        (N`` .d#= ````````.4MMMMMMM" << std::endl
		   << "MMMMMMMMMNNJ..,..dY`    .MSZZZuX# `             `              ...-.      TMMY\"```` ` ` ````,NMMMMMM" << std::endl
		   << "MMMMMMMMMMMNW#?\?!       dHZuuZZd@                   `     `..HMHWZWMm,   .HY ```` `` `` ``  JNMMMMMM" << std::endl
		   << "MMMMMMMMMMMMW%          UNmQkXXM%            `         `  jMSXdHNmXZXM..Ldt`` `` ````````` JNMMMMMMM" << std::endl
		   << "MMMMMMMMMMM#M`             ?7\"\"=      `  `.J+J...        ,MZXM^  d#ZuM),M\"```` `` ` ` ``..HNMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMH#                      `     .MBrrZVWMMmJ,   .HmXMm..HHZXM!.H-` ` `` `` ..(HMNMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMWF    `  `                   .H8rrtrrtrrrZWMN+, TNkXWWWZZHt  ?N&(.(JJggMMMNMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMNM{  ..JgkHma.,              `(#rrtrrrrtrttrrtZTN, ?WNmQkd@              gMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMNH+dMHWZZZZZZXHMN,    `      .H0rtrrd#WNmAyrtrrtrWN,   ?7!               gMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMNHWZZZZuZuZZuZuZXML`         ,MrrrrdH    ?\"WHyrrtrdH,                    gMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMNMZZZkkXZuZuZuZZuZM]         ,MrrttdM       (#rtrrrM)                    dMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMNHdH\"\"7\"YHNkZZZuZZdb     `   ,MrrrrdN      .d8trtrwM!            `   `   MMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMNM]        MKZZuuZd@          WRtrrrHN.....M8rrtrAHt                    .NMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMM#N.       dHZZuZZH%          ,MsrttrrVUUUVrtrrOd#^                    .MMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMdN.     .MSZuZZXM`           ,MsrrtrrrrrrrrAd#=    .....           `.MNMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMKN,   `(#ZZZZZWF      `      .THNmmgAwwQgM\"!  ..dMHH9VWHN.    `  `.MdMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMNMa. J#ZuuZXHF                     ?\"\"^   .+MBVdQmgyrrrM\\       (MMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMgMMHZuZZqM^                           .dBZQk#\"! _4Nrd#`     .dNMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMN#TNkqM\"                            .M0rdM-......#QM'     .MNMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMH\\` ?Wa,       `     `              4NsOrU9UUUU90d#!    JHNMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMM#M~````.THm,. `    `                   7\"HNmmggggH=    .HHMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMH#`` ``````?TN&,.              `                     .g@~MMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMH]``` `.J````` ?THm+...  `  `      `           `..(dY= ` @MMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMM\\```.(#!`` `````..MNNMMMHmgg................JdY\"= `````.HMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMM;``.M=``` ````.(MQMMMMMMMMMNMNNNNNNNNWF7?\?\?! ``` `` ```JNMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMM#MaJ@```` ` .(HMNMMMMMMMMMMMMMMMMMMMMMHb``````` `` `` `.MMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMNNMMHmmgdMNMMMMMMMMMMMMMMMMMMMMMMMMM#N.`` ` `.,`````.MdMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNWL``` ``(b` ``.HNMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNML ````,M.``.MNMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNMa..` M[.(MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNNMMMMHMNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl
		   << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << std::endl;
}