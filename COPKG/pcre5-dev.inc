@import "version.inc" ;
@import "outercurve.inc" ;

package {
    name: "pcre-dev[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";

    display-name: "PCRE developer library";
}

metadata {
    summary: "The PCRE developer library";
    description: @"Perl Compatible Regular Expressions"; 

    icon: @"pcre.png";
    
    author-version : "5.0";
    bug-tracker: "https://github.com/coapp-packages/pcre5/issues";
    stability : "0";
    licenses : {
        
    };
}

files[libs] {
    root: @"..\output\${arch}\LibR";
    
    include: {
        "pcre5static.lib",
		"pcre5.lib",
    };
    
    trim-path: all;
};

requires {
    package: "pcre-dev-common-${package-version}-any-${Package.PublicKeyToken}";
    package: "pcre[${flavor}]-${package-version}-${Package.Architecture}-${Package.PublicKeyToken}";
}

developer-library[pcre] {
    libraries : {
        libs
    };
}